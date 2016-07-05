<h3>Current Inventory Statistics</h3>
<br /><br />
Total Books: <b><?php echo ($count != NULL ? $count : "Not available.") ?></b>
<br />
Distinct Books: <b><?php echo ($distinct_count != NULL ? $distinct_count : "Not available.") ?></b>
<br />
Books Currently Checked Out: <b><?php echo ($out != NULL ? $out : "Not available.") ?></b>