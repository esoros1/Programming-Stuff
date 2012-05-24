<?php

	require_once('mysqli.php');
	
	//so we can't actually remove a book from the database, because it is a parent row for the order items table. 
	//instead, we set the qty to be -1, and any books that have a negative quantity aren't shown in the search results, 
	//and customer's can't add them to the table.
	
	
	$ISBN = $db_obj->real_escape_string($_POST['ISBN']);
	//we have to delete the row from the stock table, then the book table
	$query = "UPDATE proj_stock SET qty = -1 WHERE ISBN = '$ISBN'";
	
	$db_obj->query($query);
		
	if($db_obj->affected_rows == 1)
	{
		header('location:removebook?success=1');
		exit();
	}	
	else
	{
		header('location:removebook?success=-1');
		exit();
	}

	

?>