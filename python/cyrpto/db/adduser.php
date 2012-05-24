<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8" />
<link rel="stylesheet" type="text/css" href="styles.css" />
<title>Untitled Document</title>
</head>
<body>
	<?php
		require_once("header.php");	
		require_once("add_new_user.php");
		
		$firstname = $_POST["firstname"];
		$lastname = $_POST["lastname"];
		
		$check = addNewUser($_POST['firstname'],$_POST['lastname'],$_POST['email'],$_POST['address'],
					$_POST['phone'],$_POST['city'],$_POST['state'],$_POST['zip'],$_POST['pass']);			
		
		if($check)
			header('location:index?pass=1');
		else
			header('location:newuser?pass=-1');		
		
	?>

</body>
</html>