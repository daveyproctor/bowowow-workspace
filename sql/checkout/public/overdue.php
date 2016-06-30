<?php

    // configuration
    require("../includes/config.php"); 
    require("checkout.php");
    
    
    
    if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        $first = $_POST["first"];
        $last = $_POST["last"];
        $num = $_POST["num"];
        $name = $first . " " . $last;
        
        $user_exists = count(query("SELECT * FROM members WHERE first_name = ? AND last_name = ?", $first, $last)) > 0;
        
        $checked_out = extract_count(checked_out($first, $last));
        $overdue = extract_count(late($first, $last, today()));
        $approve_checkout = approve_checkout($checked_out, $overdue, $num);
        
        if ($checked_out === NULL || $overdue === NULL || $approve_checkout === NULL)
            render("overdue.php", ["title" => "Overdue", "null_results" => true]);
        
        render("overdue.php", ["title" => "Overdue", "submitted" => true, "user_exists" => $user_exists,
            "out" => $checked_out, "overdue" => $overdue, "approved" => $approve_checkout, "name" => $name, "num" => $num]);
    }
    else
    {
        render("overdue.php", ["title" => "Overdue"]);
    }

?>
