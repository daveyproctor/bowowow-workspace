<?php

    /**
     * helpers.php
     *
     * CSCI-P 14300
     * checkout
     * Adapted from CS50
     *
     * TODO
     */
     
    require_once("../includes/config.php");
    
    // PROBLEM 0 - HOMEPAGE
    
    // 0.0 - BOOKS
    function books() {
        return query("SELECT title, author_id from books");
    }
    
    // 0.1 - AUTHOR
    function author_name($author_id) {
        // TODO
        return query("SELECT first_name, last_name FROM authors WHERE id = ?", $author_id);
    }
    
    // PROBLEM 1 - INVENTORY
    
    // 1.0 - TOTAL
    function book_count() {
        return query("SELECT COUNT(*) FROM books");
    }
    
    // 1.1 - DISTINCT
    function distinct_book_count() {
        return query("SELECT COUNT(DISTINCT title) FROM books");
    }
    
    // 1.2 - OUT
    function currently_out() {
        return query("SELECT COUNT(*) FROM transactions WHERE returned = 0");
    }
    
    // PROBLEM 2 - CATALOG
    
    // 2.0 - ANTHOLOGY
    function books_by_author($author_last) {
        return query("SELECT DISTINCT books.title FROM books INNER JOIN authors ON books.author_id
        = authors.id WHERE authors.last_name = ?", $author_last);
    }
    
    // 2.1 - SUGGESTION
    function suggest($books) {
        return $books[array_rand($books)];
    }
    
    // PROBLEM 3 - OVERDUE
    
    // 3.0 - BORROWED
    function checked_out($first_name, $last_name) {
        return query("SELECT COUNT(*) FROM transactions INNER JOIN members ON members.id = 
        transactions.borrower_id WHERE transactions.returned = 0 AND 
        members.first_name = ? AND members.last_name = ?", $first_name, $last_name);
    }
    
    // 3.1 - LATE
    function late($first_name, $last_name, $today) {
        return query("SELECT COUNT(*) FROM transactions INNER JOIN members ON members.id = 
        transactions.borrower_id WHERE transactions.returned = 0 AND transactions.due_date < ?
        AND members.first_name = ? AND members.last_name = ?", $today, $first_name, $last_name);
    }
    
    // 3.2 - ELIGIBLE
    function approve_checkout($checked_out, $overdue, $num) {
        if ($checked_out + $num > 5 || $overdue >= 1)
        {
            return false;
        }
        return true;
    }
    
?>