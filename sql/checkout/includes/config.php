<?php

    /**
     * config.php
     *
     * CSCI-P 14300
     * checkout
     * Adapted from CS50
     *
     * Configures app.
     */

    // display errors, warnings, and notices
    ini_set("display_errors", true);
    error_reporting(E_ALL);

    // requirements
    require("helpers.php");

    define("DATABASE", "checkout");
    define("SERVER", getenv("IP"));
    define("USERNAME", getenv("C9_USER"));
    
    define("PASSWORD", "v1kCjsvLYytrBTGV");
?>
