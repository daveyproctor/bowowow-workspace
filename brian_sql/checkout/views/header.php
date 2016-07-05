<!DOCTYPE html>

<html>

    <head>

        <!-- http://getbootstrap.com/ -->
        <link href="/css/bootstrap.min.css" rel="stylesheet"/>

        <link href="/css/styles.css" rel="stylesheet"/>

        <?php if (isset($title)): ?>
            <title>CSCI P-14300 Checkout: <?= htmlspecialchars($title) ?></title>
        <?php else: ?>
            <title>CSCI P-14300 Checkout</title>
        <?php endif ?>

        <!-- https://jquery.com/ -->
        <script src="/js/jquery-1.11.3.min.js"></script>

        <!-- http://getbootstrap.com/ -->
        <script src="/js/bootstrap.min.js"></script>

        <script src="/js/scripts.js"></script>

    </head>

    <body>

        <div class="container">

            <div id="top">
                <div>
                      <h1>CSCI P-14300 Checkout</h1>
                </div>

                    <ul class="nav nav-pills">
                        <li><a href="index.php">Homepage</a></li>
                        <li><a href="inventory.php">Inventory</a></li>
                        <li><a href="catalog.php">Catalog</a></li>
                        <li><a href="overdue.php">Overdue</a></li>
                    </ul>

            </div>

            <div id="middle">
