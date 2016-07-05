<?php

    // configuration
    require("../includes/config.php"); 
    require("checkout.php");
    
    $book_count = extract_count(book_count());
    $distinct_book_count = extract_count(distinct_book_count());
    $currently_out = extract_count(currently_out());
    
    render("inventory.php", ["title" => "Inventory", "count" => $book_count, "distinct_count" => $distinct_book_count, "out" => $currently_out]);

?>
