<h3>Checkout Counter</h3>
<br /><br />
<b>Rules for the Library:</b><br />
Library members may have <b>at most 5</b> books checked out at any given time.<br />
If a library member has any overdue books, they are not eligible to check out additional books.

<br /><br />
<form method="post" action="overdue.php">
    <input style="form-control" type="text" name="first" placeholder="First Name" autofocus>
    <br />
    <input style="form-control" type="text" name="last" placeholder="Last Name">
    <br />
    <input style="form-control" type="number" name="num" placeholder="Books to Borrow">
    <br /><br />
    <button class="btn btn-default" type="submit">Submit</button>
</form>
<br /><br />

<?php if (isset($null_results)): ?>
    Status is <b>not available.</b>
<?php endif ?>

<?php if (isset($submitted)): ?>
    Status of <b><?php echo htmlspecialchars($name) ?></b>:
    <br /><br />
    <?php if ($user_exists == false): ?>
        The member does not exist in the library database.
    <?php else: ?>
        The member currently has <b><?php echo htmlspecialchars($out) ?></b> books checked out. <br />
        The member currently has <b><?php echo htmlspecialchars($overdue) ?></b> books overdue. <br />
        The member is trying to check out <b><?php echo htmlspecialchars($num) ?></b> books. <br />
        The user is <b><?php echo $approved ? "approved" : "not approved" ?></b> to complete the checkout.
    <?php endif ?>
<?php endif ?>