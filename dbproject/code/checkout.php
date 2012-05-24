<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8" />
<link rel="stylesheet" type="text/css" href="styles.css" />
<title>That's Bargain! Books</title>
</head>
<body>

<?php
	
		
	
	session_start();
	date_default_timezone_set('UTC');
	require_once("mysqli.php");
	require_once("header.php");
	
	//generate a 12 digit order id for the customer
	//first two digits -- last two digits of the year
	//next two digits -- the month
	//next two digits -- the day
	//six random digits
	function generateOrderID()
	{
		$dateStr = date("Ymd");
		return substr($dateStr,2,2) . substr($dateStr,4,2) . substr($dateStr,6,2) . rand(100000,999999);
	}
		
	//they are a guest, and need to sign up for an account before they can checkout
	if(!$_SESSION['email'])
	{
		header('location:newuser.html?guest=1');
		exit();
	}
	
	if(!$_SESSION['cart'])
	{
		echo '<p align="center">Your Cart is Empty</p>';
		exit();
	}
		
	//make sure that the orderID is valid.
	do 
	{
		$orderID = generateOrderID();
		//try to insert the orderID into the table. If it fails, then the orderID alreayd exists, and we need to fix that
		$query = "INSERT INTO proj_orders VALUES('$orderID','" . $_SESSION['email'] . "',CURRENT_TIMESTAMP())";
		$result_obj = $db_obj->query($query);
	} while ($db_obj->affected_rows != 1);
	
	if($db_obj->affected_rows == 1)
	{
		
		//transcation that adds all of the itmes in the cart to the proj_items_order table
		$db_obj->autocommit(FALSE);
		$err = FALSE;
		foreach($_SESSION['cart'] as $ISBN => $bookArr)
		{
			$ISBN = $bookArr['ISBN'];
			$qty = $bookArr['qty'];
			$amt = number_format($bookArr['qty'] * $bookArr['price'], 2);
			$query = "INSERT INTO proj_order_items VALUES('$orderID', '$ISBN', '$qty', '$amt')";
			$db_obj->query($query);
			//if it didn't suceed, raise the error flag so we can rollback the changes
			if($db_obj->affected_rows == 0)
			{
				$err = TRUE;
			}
		}
		
		if(!$err)
		{
			$db_obj->commit();
			$db_obj->autocommit(TRUE);
		}
	
		
		echo '<p align="center">Thank you for your purchase '. $_SESSION['firstname'] . ' ' . $_SESSION['lastname']. '</br>';
		echo '<a href="displayRecipt.php?orderID='. $orderID . '">View Receipt</a></p>';
	
		//update the stock in the database. Probably going to use a trigger. IDK yet. 
		reset($_SESSION['cart']);
		
		
		
		//get rid of all the items in the shopping cart
		unset($_SESSION['cart']);
	}
	//the only reason we should get here is if we run out of orderID's, which we shouldn't.  
	else
	{
		echo "Invalid ORDERID";
	
	}
?>

</body>
</html>