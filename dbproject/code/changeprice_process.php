<?php

	require_once('mysqli.php');
	$ISBN = $db_obj->real_escape_string($_POST['ISBN']);
	$price = $db_obj->real_escape_string($_POST['price']);
	
	$query = "UPDATE proj_book SET price = " . $price . " WHERE ISBN = '$ISBN'";
	$db_obj->query($query);
	
	
	//if the query was unsuccessfull, then the book is not in the system.
	if($db_obj->affected_rows == 1)
	{
		header('location:changeprice.php?success=1');
		exit();
	}
	else
	{
		header('location:changeprice.php?success=-1');
		exit();
	}

?>