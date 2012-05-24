<?php

	require_once('mysqli.php');
	
	$ISBN = $db_obj->real_escape_string($_POST['ISBN']);
	$qty = $db_obj->real_escape_string($_POST['qty']);
	
	
	//try to remove the value from stock. It if fails, the book is not in the DB.
	$query = "DELETE FROM proj_stock WHERE ISBN = '$ISBN'";
	$db_obj->query($query);
	
	if($db_obj->affected_rows == 0)
	{
		header('location:updatestock.php?pass=-1');
		exit();
	}
	
	//now insert the new value
	$query = "INSERT INTO proj_stock VALUE('$ISBN'," .  $qty .")";
	echo $query;
	$db_obj->query($query);

	if($db_obj->affected_rows == 1)
	{
		header('location:updatestock.php?pass=1');
		exit();
	}
	else
	{
		header('location:updatestock.php?pass=-1');
		exit();
	}

?>