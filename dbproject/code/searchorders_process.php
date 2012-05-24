<?php

	require_once('mysqli.php');
	
	
	$search = $db_obj->real_escape_string($_POST['search']);

	switch($_POST['search_type'])
	{
	
		//search by orderID
		case 1:
			$query = "SELECT * FROM proj_orders WHERE order_ID = '$search'";
			$result_obj = $db_obj->query($query);	
	
			//if it was successful, then redirect them to view order, else send back an error via GET
			if( $db_obj->affected_rows == 1)
			{
				header('location:displayRecipt.php?orderID='.$search);
				exit();
			}
			else
			{
				header('location:searchorders.php?success=-1');
				exit();
			}
			break;
		//search by email
		case 2:	
			$query = "SELECT * FROM proj_customer WHERE email = '$search'";
			$result_obj = $db_obj->query($query);	
	
			//if it was successful, then redirect them to display all of the user's orders, else send back an error via GET
			if( $db_obj->affected_rows == 1)
			{
				header('location:myorders.php?email='.$search);
				exit();
			}
			else
			{
				header('location:searchorders.php?success=-2');
				exit();
			}
			break;
			
	}
?>