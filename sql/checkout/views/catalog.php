<h3>Library Catalog</h3>
<br /><br />
<form method="post" action="catalog.php">
    <input style="form-control" type="text" name="last" placeholder="Author Last Name" autofocus>
    <br /><br />
    <button class="btn btn-default" type="submit">Search Catalog</button>
</form>

<br /><br />
<?php if (isset($books)): ?>
    Search Results for <b><?php echo htmlspecialchars($last) ?></b>
    <br /><br />
    <b>Book Titles</b><br />
        <?php foreach ($books as $book): ?>
            <?php echo htmlspecialchars($book["title"]) . "<br />" ?>
        <?php endforeach ?>
        <?php if (count($books) == 0): ?>
            There were no books matching your query.
        <?php endif ?>
    <br /><br />
    <?php if ($suggestion != NULL): ?>
        Suggested Book for Your Reading: <?php echo htmlspecialchars($suggestion["title"]) ?>
    <?php else: ?>
        Suggested Book for Your Reading: <b>Not available.</b>
    <?php endif ?>
<?php endif ?>