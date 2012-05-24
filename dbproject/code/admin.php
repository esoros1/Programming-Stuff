<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8" />
<link rel="stylesheet" type="text/css" href="styles.css" />
<title>That's Bargain! Books</title>
</head>
<body>
	
	<?php 
	
		require('header.php'); 
		//if they aren't admin, just redirect them to the home page	
		if(!isset($_SESSION['admin']))
		{
			header('location:userhome');
			exit();
		}
	
	?>
	
	<div class="login-reg">
		<h1 class="form-text">Admin Tools</h1>
		<p align="center">
		<a href="addbook.php">Add Book</a></br>
		<a href="removebook.php">Remove Book</a></br>
		<a href="changeprice.php">Change Prices</a></br>
		<a href="updatestock.php">Update Stock</a></br>
		<a href="setadmin.php">Set Admin Privileges</a></br>
		<a href="customersearch.php">Search Customers</a></br>
		<a href="searchorders.php">Search Orders</a>
		</p>
	</div>

</body>
</html>