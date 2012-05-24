<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8" />
<link rel="stylesheet" type="text/css" href="styles.css" />
<title>That's Bargain! Books</title>
</head>
<body>
	
	<?php
		//add a user to the database. 

		require_once("add_new_user.php");
		
		$firstname = $_POST["firstname"];
		$lastname = $_POST["lastname"];
		$email = $_POST['email'];
		$address = $_POST['address'];
		$phone = $_POST['phone'];
		$city = $_POST['city'];
		$state = $_POST['state'];
		$zip = $_POST['zip'];
		$pass = $_POST['pass'];
		
		
		$check = addNewUser($_POST['firstname'],$_POST['lastname'],$_POST['email'],$_POST['address'],
					$_POST['phone'],$_POST['city'],$_POST['state'],$_POST['zip'],$_POST['pass']);			
		


		//if they were brought from the checkout page, then we have to set all of the session information
		//and redirect them to the checkout page so the order can be completed like normal. 
		if( isset($_POST['guest']) )
		{
			if($check)
			{
				session_start();
				$_SESSION['firstname'] = $firstname;
				$_SESSION['lastname'] = $lastname;
				$_SESSION['email'] = $email;
				$_SESSION['address_street'] = $address;
				$_SESSION['phone']	= $phone;
				$_SESSION['address_city'] = $city;
				$_SESSION['address_state'] = $state;
				$_SESSION['address_zip'] = $zip;
				header('location:checkout.php');
				exit();	
			}
			//the user already exists in the system. redirect them to the register page again
			else
			{
				header('location:newuser.html?guest=1&pass=-1');
				exit();			
			}

		}
		//they just choose to sign up from the login page. Just redirect to index. 
		else
		{
			if($check)
				header('location:index?pass=1');
			else
				header('location:newuser?pass=-1');		
		}
		
		
	
	?>

</body>
</html>