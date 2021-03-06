<?php

    /**
     * register-2.php
     *
     * Computer Science 50
     * David J. Malan
     *
     * Implements a registration form for Frosh IMs.  Informs user of 
     * any errors.
     */

?>

<!DOCTYPE html>

<html>
    <head>
        <title>Frosh IMs</title>
    </head>
    <body>
        <?php if (empty($_POST["name"]) || empty($_POST["comfort"]) || empty($_POST["dorm"])): ?>
            You must provide your name, comfort, and dorm!  Go <a href="froshims-2.php">back</a>.
        <?php else: ?>
            You are registered!  (Well, not really.)
        <?php endif ?>
    </body>
</html>
