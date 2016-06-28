#1
int hash(const char* word)
{
 return (toupper(word[0]) - 'A');
}
While simple (and thus fast to compute), this hash function isn't necessarily the best. Critique this 
hash function, identifying and explaining a downside. 


This is something that master is typing.

I, Stephanie, make this change M2.

change from master M2.

#2
(5 points.)  Consider the types below.
typedef char* string;
typedef struct node
{
 int n;
 struct node* next;
}
node;
typedef struct
{
 char* name;
 char* house;
}
student;
Complete the table below by recording to the right of each type its size in bytes (not bits).  Assume 
a 32Mbit architecture like the CS50 Appliance. 

#3
Consider the program below, wherein list is an unsorted doublyMlinked list of integers.
#include <stdbool.h>
#include <stdlib.h>
typedef struct node
{
 int n;
 struct node* prev;
 struct node* next;
}
node;
node* list = NULL;
void insert(int n);
void remove(int n);
int main(void)
{
 insert(50);
 insert(34);
 insert(59);
 insert(20);
 insert(106);
 insert(36);
 insert(52);
 remove(50);
}
11. (4  points.)    Complete  the  implementation  of insert below  in  such  a  way  that  it  inserts n into 
list in constant time (even if already present).
void insert(int n)

void insert(int n)
{
 node* ptr = malloc(sizeof(node));
 if (ptr != NULL)
 {
 ptr->n = n;
 ptr->prev = NULL;
 ptr->next = list;
 if (list != NULL)
 {
 list->prev = ptr;
 }
 list = ptr;
 }
}