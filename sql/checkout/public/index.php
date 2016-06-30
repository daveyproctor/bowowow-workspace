<?php

    // configuration
    require("../includes/config.php"); 
    require("checkout.php");
    
    $books = books();
    $book = NULL;
    $author = NULL;
    if ($books != NULL)
        $book = $books[array_rand($books)];
    
    if ($book != NULL)
    {
        $author = $book["author_id"];
        $author = author_name($author)[0];
    }
   
    
    render("index.php", ["title" => "Homepage", "book" => $book, "author" => $author]);

?>
