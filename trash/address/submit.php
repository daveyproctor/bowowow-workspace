<!DOCTYPE html>
<html>
    <?php
    if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        
        //"a" for append
        $handle = fopen("contacts.csv", "a");
        //$_POST["firstname"]
        
        if(empty($_POST["firstname"]) ||
        empty($_POST["lastname"]) ||
        empty($_POST["street"]) ||
        empty($_POST["city"]) ||
        empty($_POST["state"]) ||
        empty($_POST["zipcode"]) ||
        empty($_POST["cakepreference"])
        )
        {
            //header( 'Location: https://bowowow-dwp7.c9users.io/whoops.html' ) ;
            header('location: whoops.html');
            exit;
        }
        
        fputcsv($handle, array($_POST["firstname"], $_POST["lastname"], $_POST["street"], $_POST["city"],
        $_POST["state"], $_POST["zipcode"], $_POST["cakepreference"]));
        fclose($handle);
        
    }
    ?>
    <head>
        <title>Submitted!</title>
        <link rel="stylesheet" href="styles.css" type="text/css"/>
    </head>
    <body>
        <h2>Your response has been submitted!</h2>
        <form action="/">
            <input type="submit" value="Submit another response!"/>
        </form> 
    </body>
<html></html>