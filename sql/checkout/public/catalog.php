<?php

    // configuration
    require("../includes/config.php"); 
    require("checkout.php");
    
    if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        $last = $_POST["last"];
        
        $books = books_by_author($last);
        $suggestion = count($books) == 0 ? NULL : suggest($books);
        
        render("catalog.php", ["title" => "Catalog", "submitted" => true, "books" => $books, "suggestion" => $suggestion, "last" => $last]);
    }
    else
    {
        render("catalog.php", ["title" => "Catalog"]);
    }
?>
