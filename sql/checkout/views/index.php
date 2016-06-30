<h3>Welcome to the CSCI P-14300 public library!</h3>
<br /><br />
<?php if ($book != NULL && $author != NULL): ?>
<b>Today's Featured Book:</b><br />
<?php echo htmlspecialchars($book["title"]) ?><br />
Written by <?php echo htmlspecialchars($author["first_name"] . " " . $author["last_name"]) ?>
<?php else: ?>
Today's featured book is currently unavailable.
<?php endif ?>