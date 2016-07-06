#define _BSD_SOURCE

#include <ctype.h>
#include <ncurses.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <unistd.h>
#include "blockdude.h"

// global struct to encapsulate data
struct {
    int lvl;
    int attempts;
    int top, bottom, left, right;
    int posy, posx;
    bool blocked;
} g;

// globals
bool win = false;

// prototypes
bool check_win(char direction);
void cursor(void);
void draw_banners(void);
void draw_border(void);
void draw_level(void);
void handle_signal(int signum);
void levelup(void);
void redraw_all(void);
void restart_level(void);
void reposition(int ch);
bool startup(void);
void shutdown(void);

int main(int argc, char* argv[])
{
    // ensure proper usage
    if (argc == 1)
        g.lvl = 1;
    else if (argc == 2)
    {
        switch(atoi(argv[1]))
        {
            case CODE2:
                g.lvl = 2;
                break;
            case CODE3:
                g.lvl = 3;
                break;
            case CODE4:
                g.lvl = 4;
                break;
            case CODE5:
                g.lvl = 5;
                break;
            default:
                printf("Incorrect code. Starting with Level 0\n");
                usleep(3000000);
                g.lvl = 1;
                break;
        }
    }
    else
    {
        printf("Usage: %s [code]\n", argv[0] + 2);
        return 1;
    }
    
    // startup window
    if (startup() == false)
    {
        printf("Startup failed!\n");
        return -1;
    }
    
    // register handler for SIGWINCH (SIGnal WINdow CHanged)
    signal(SIGWINCH, (void (*)(int)) handle_signal);
    
    // start
    g.attempts = 0;
    restart_level();
    int ch;
    do
    {
        // renew screen and wait for key
        refresh();
        ch = getch();
        ch = toupper(ch);
        
        // do something with key input
        switch(ch)
        {
            case KEY_UP: case KEY_DOWN: case KEY_LEFT: case KEY_RIGHT:
                reposition(ch);
                break;
            case 'N':
                g.lvl = 0;
                g.attempts = 0;
            case 'R':
                g.attempts++;
                restart_level();
                break;
        }
        
        // after user wins, wait for key input, then exit
        if (win)
        {
            timeout(-1);
            getch();
            break;
        }
        
    } while (ch != 'Q');
    
    shutdown();
    
    // tidy up the screen (using ANSI escape sequences)
    printf("\033[2J");
    printf("\033[%d;%dH", 0, 0);

    // that's all folks
    printf("\nkthxbai!\n\n");
    return 0;
}

// checks if the user will win after the character moves
bool check_win(char direction)
{
    if (direction == 'L')
    {
        if (mvinch(g.posy - 1, g.posx - DISPLACE) == EXIT)
        {
            return true;
        }
        else if (mvinch(g.posy, g.posx - DISPLACE) == EXIT)
        {
            return true;
        }
        else if (mvinch(g.posy, g.posx - DISPLACE) == SPACE)
        {
            int place = g.posy;
            while (mvinch(place, g.posx - DISPLACE) == SPACE)
                place++;
            if (mvinch(place, g.posx - DISPLACE) == EXIT)
                return true;
        }
    }
    else
    {
        if (mvinch(g.posy - 1, g.posx + DISPLACE) == EXIT)
        {
            return true;
        }
        else if (mvinch(g.posy, g.posx + DISPLACE) == EXIT)
        {
            return true;
        }
        else if (mvinch(g.posy, g.posx + DISPLACE) == SPACE)
        {
            int place = g.posy;
            while (mvinch(place, g.posx + DISPLACE) == SPACE)
                place++;
            if (mvinch(place, g.posx + DISPLACE) == EXIT)
                return true;
        }
    }
    return false;
}

// displays cursor
void cursor(void)
{
    move(g.posy, g.posx);
}

// draws screen's banners
void draw_banners(void)
{
    // get screen dimensions
    int maxy, maxx;
    getmaxyx(stdscr, maxy, maxx);
    
    // clear screen
    for (int i = 0; i < maxx; i++)
    {
        mvaddch(0, i, SPACE);
        mvaddch(maxy-1, i, SPACE);
    }
    
    // draw header
    char header[maxx+1];
    sprintf(header, "%s by %s", TITLE, AUTHOR);
    mvaddstr(0, (maxx - strlen(header)) / 2, header);

    // draw footer
    char footer[maxx+1];
    sprintf(footer, "Level %i   Attempts: %i", g.lvl, g.attempts);
    mvaddstr(maxy-2, (maxx - strlen(footer))/2, footer);
    mvaddstr(maxy-1, 1, "[N]ew Game");
    mvaddstr(maxy-1, (maxx-17)/2, "[R]estart Level");
    mvaddstr(maxy-1, maxx-13, "[Q]uit Game");
    
    // draw level code banner
    char lvlbanner[maxx+1];
    switch(g.lvl)
    {
        case 2:
            sprintf(lvlbanner, "Level Code: %i", CODE2);
            break;
        case 3:
            sprintf(lvlbanner, "Level Code: %i", CODE3);
            break;
        case 4:
            sprintf(lvlbanner, "Level Code: %i", CODE4);
            break;
        case 5:
            sprintf(lvlbanner, "Level Code: %i", CODE5);
            break;
        default:
            sprintf(lvlbanner, "Use arrow keys to move, pick up, and drop");
            break;
    }
    mvaddstr(1, (maxx - strlen(lvlbanner)) / 2, lvlbanner);
}

// draws screens playable window
void draw_border(void)
{
    // get screen dimensions
    int maxy, maxx;
    getmaxyx(stdscr, maxy, maxx);
    
    // define playable windows dimensions
    g.top = 2;
    g.bottom = maxy - 3;
    g.left = maxx/2 - WIDTH/2;
    g.right = maxx/2 + WIDTH/2;
    
    // draw border's top
    mvaddch(g.top, g.left, BCORNER);
    for (int i = 1; i < WIDTH; i++)
        mvaddch(g.top, g.left + i, BORDERTB);
    mvaddch(g.top, g.right, BCORNER);
    
    // draw border's sides
    for (int i = g.top + 1; i < g.bottom; i++)
    {
        mvaddch(i, g.left, BORDERLR);
        for (int j = 1; j < WIDTH; j++)
            mvaddch(i, g.left + j, SPACE);
        mvaddch(i, g.right, BORDERLR);
    }
    
    // draw border's bottom
    mvaddch(g.bottom, g.left, BCORNER);
    for (int i = 1; i < WIDTH; i++)
        mvaddch(g.bottom, g.left + i, BORDERTB);
    mvaddch(g.bottom, g.right, BCORNER);
}

// draws level
void draw_level(void)
{
    // file to open
    char* lvlfile;
    switch (g.lvl)
    {
        case 2:
            lvlfile = L2;
            break;
        case 3:
            lvlfile = L3;
            break;
        case 4:
            lvlfile = L4;
            break;
        case 5:
            lvlfile = L5;
            break;
        case 1: default:
            lvlfile = L1;
            break;
    }
    
    // open file
    FILE* file = fopen(lvlfile, "r");
    if (file == NULL)
    {
        shutdown();
        printf("File Error\n");
        exit(2);
    }
    
    // info buffer
    char info[DATALENGTH];
    
    // text parsing
    while (fgets(info, DATALENGTH, file) != NULL)
    {
        // get letter
        char* letter = strtok(info, " \n");
        char* num;
        
        // pillaring
        if (strcasecmp(letter, "P") == 0)
        {
            int pillar_pos = g.left + 1;
            while ((num = strtok(NULL, " \n")) && pillar_pos < g.right)
            {
                int n = atoi(num);
                for (int i = 0; i < n; i++)
                    mvaddch(g.bottom - i - 1, pillar_pos, BRICK);
                pillar_pos += DISPLACE;
            }
        }
        
        // blocking
        else if (strcasecmp(letter, "B") == 0)
        {
            while ((num = strtok(NULL, " \n")))
            {
                int n = g.left + atoi(num);
                if (n <= g.left)
                    n = g.left + 1;
                else if (n >= g.right)
                    n = g.right - 1;
                int block_pos = g.bottom - 1;
                while (mvinch(block_pos, n) != SPACE)
                    block_pos--;
                mvaddch(block_pos, n, BLOCK);
            }
        }
        
        // level exit
        else if (strcasecmp(letter, "E") == 0)
        {
            char* num = strtok(NULL, "  \n");
            int n = g.left + atoi(num);
            if (n <= g.left)
                n = g.left + 1;
            else if (n >= g.right)
                n = g.right - 1;
            int exit_pos = g.bottom - 1;
            while (mvinch(exit_pos, n) != SPACE)
                exit_pos--;
            mvaddch(exit_pos, n, EXIT);
        }
        
        // character starting position
        else if (strcasecmp(letter, "C") == 0)
        {
            g.posy = g.bottom - 1;
            g.posx = g.left + atoi(strtok(NULL, " \n"));
            if (g.posx <= g.left)
                g.posx = g.left + 1;
            else if (g.posx >= g.right)
                g.posx = g.right - 1;
            while (mvinch(g.posy, g.posx) != SPACE)
                g.posy--;
            mvaddch(g.posy, g.posx, PLAYER);
        }
        
        // remove bricks
        else if (strcasecmp(letter, "R") == 0)
        {
            int col = g.left + atoi(strtok(NULL, " \n"));
            if (col <= g.left)
                col = g.left + 1;
            else if (col >= g.right)
                col = g.right - 1;
            int end = g.bottom - atoi(strtok(NULL, " \n"));
            if (end > g.bottom)
                end = g.bottom;
            int start = g.bottom - atoi(strtok(NULL, " \n"));
            if (start <= g.top)
                start = g.top + 1;
            for (;start < end; start++)
                mvaddch(start, col, SPACE);
        }
        
        // incorrect format
        else
        {
            shutdown();
            printf("Incorrect file format\n");
            exit(3);
        }
    }
    
    // close file
    fclose(file);
    cursor();
}

// handles screen resizing
void handle_signal(int signum)
{
    // handle a change in the window (i.e., a resizing)
    if (signum == SIGWINCH)
        redraw_all();

    // re-register myself so this signal gets handled in future too
    signal(signum, (void (*)(int)) handle_signal);
}

// goes to next level unless user wins
void levelup(void)
{
    // win
    if (g.lvl == LASTLVL)
    {
        win = !win;
        clear();
        int maxy, maxx;
        getmaxyx(stdscr, maxy, maxx);
        mvaddstr(maxy/2 - 1, (maxx-8)/2, "YOU WIN!");
        char winner[maxx+1];
        sprintf(winner, "Attempts: %i", g.attempts);
        mvaddstr(maxy/2, (maxx - strlen(winner))/2, winner);
        move(maxy/2 + 1, maxx/2 - 1);
    }
    
    // next level
    else
    {
        g.lvl++;
        restart_level();
    }
}

// redraws everything to the screen
void redraw_all(void)
{
     // reset ncurses
    endwin();
    refresh();

    // clear screen
    clear();

    // re-draw everything
    draw_banners();
    draw_border();
    draw_level();
}

// restarts level
void restart_level(void)
{
    g.blocked = false;
    redraw_all();
}

// moving the character on arrow key input
void reposition(int ch)
{
    switch(ch)
    {
        // pick up block key
        case KEY_UP:
            // TODO
            cursor();
            break;
            
        // drop block key
        case KEY_DOWN:
            // TODO
            cursor();
            break;
            
        // move left key
        case KEY_LEFT:
            // if facing right, face left
            if (inch() == PRIGHT)
                addch(PLEFT);
            // make sure movement is allowed
            else if (g.posx - DISPLACE > g.left)
            {
                // check for win
                if (check_win('L'))
                {
                    clear();
                    levelup();
                    return;
                }
                
                // if position left is a brick or block, move left and up if possible
                if (mvinch(g.posy, g.posx - DISPLACE) != SPACE)
                {
                    if (mvinch(g.posy - 1, g.posx - DISPLACE) == SPACE)
                    {
                        mvaddch(g.posy, g.posx, SPACE);
                        mvaddch(g.posy - 1, g.posx, SPACE);
                        g.posy--;
                        g.posx -= DISPLACE;
                        mvaddch(g.posy, g.posx, PLEFT);
                    } 
                }
                else
                {
                    // move left and below
                    if (mvinch(g.posy + 1, g.posx - DISPLACE) == SPACE)
                    {
                        mvaddch(g.posy, g.posx, SPACE);
                        mvaddch(g.posy - 1, g.posx, SPACE);
                        while (mvinch(g.posy + 1, g.posx - DISPLACE) == SPACE)
                            g.posy++;
                        g.posx -= DISPLACE;
                        mvaddch(g.posy, g.posx, PLEFT);
                    }
                    // move left only
                    else if (mvinch(g.posy, g.posx - DISPLACE) == SPACE)
                    {
                        mvaddch(g.posy, g.posx, SPACE);
                        mvaddch(g.posy - 1, g.posx, SPACE);
                        g.posx -= DISPLACE;
                        mvaddch(g.posy, g.posx, PLEFT);
                    }   
                }
                
                // move block with you if you have block
                if (g.blocked)
                {
                    mvaddch(g.posy - 1, g.posx, BLOCK);
                }
            }
            // reset cursor
            cursor();
            break;
            
        case KEY_RIGHT:
            // if facing left, face right
            if (inch() == PLEFT)
                addch(PRIGHT);
            // ensure movement is allowed
            else if (g.posx + DISPLACE < g.right)
            {
                // check for win
                if (check_win('R'))
                {
                    clear();
                    levelup();
                    return;
                }
                
                // if position right is brick or block, move right and up if possible
                if (mvinch(g.posy, g.posx + DISPLACE) != SPACE)
                {
                    if (mvinch(g.posy - 1, g.posx + DISPLACE) == SPACE)
                    {
                        mvaddch(g.posy, g.posx, SPACE);
                        mvaddch(g.posy - 1, g.posx, SPACE);
                        g.posy--;
                        g.posx += DISPLACE;
                        mvaddch(g.posy, g.posx, PRIGHT);
                    }
                }
                else
                {
                    // move right and below
                    if (mvinch(g.posy + 1, g.posx + DISPLACE) == SPACE)
                    {
                        mvaddch(g.posy, g.posx, SPACE);
                        mvaddch(g.posy - 1, g.posx, SPACE);
                        while (mvinch(g.posy + 1, g.posx + DISPLACE) == SPACE)
                            g.posy++;
                        g.posx += DISPLACE;
                        mvaddch(g.posy, g.posx, PRIGHT);
                    }
                    // move right only
                    else if (mvinch(g.posy, g.posx + DISPLACE) == SPACE)
                    {
                        mvaddch(g.posy, g.posx, SPACE);
                        mvaddch(g.posy - 1, g.posx, SPACE);
                        g.posx += DISPLACE;
                        mvaddch(g.posy, g.posx, PRIGHT);
                    }   
                }
                
                // move block with you if you have block
                if (g.blocked)
                {
                    mvaddch(g.posy - 1, g.posx, BLOCK);
                }
            }
            // reset curosr
            cursor();
            break;
    }
}

// shutdowns and closes window
void shutdown(void)
{
    endwin();
}

// starts up window
bool startup(void)
{
    // initialize ncurses
    if (initscr() == NULL)
        return false;

    // don't echo keyboard input
    if (noecho() == ERR)
    {
        endwin();
        return false;
    }

    // disable line buffering and certain signals
    if (raw() == ERR)
    {
        endwin();
        return false;
    }

    // enable arrow keys
    if (keypad(stdscr, true) == ERR)
    {
        endwin();
        return false;
    }

    // wait 1000 ms at a time for input
    timeout(1000);

    // w00t
    return true;
}