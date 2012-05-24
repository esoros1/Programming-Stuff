<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8" />
<link rel="stylesheet" type="text/css" href="styles.css" />

<title>That's Bargain! Books</title>
</head>

<body>
	<?php
		require_once("header.php");	
		require_once("mysqli.php");
		require_once('globals.php');
		
			
		$isRegistered = isRegisteredEmail($_POST['email']);
		if($isRegistered['email'])
		{
			
			//generate a random sting of 20 letter for there new password
			$randPass = "";
			for($i = 0; $i < 20; ++$i)
			{
				//the range of printable ascii characters is 33 - 126. 
				$randPass .= chr(rand(33,126));
			}
			
			echo $randPass;
			
			//send them an email telling them that there password has been reset
			$message = "A random password has been generated for you\n";
			$message .= "Your new password is: " . $randPass . "\n";
			$message .= "Please login and change your password.";
			
			//actually insert the new password
			if ( changePassword($_POST['email'], $randPass) )
			{
				mail($_POST['email'],"Password Reset",$message);
				header('location:forgotpass.php?pass=1');
				exit();
			}
		}
		else
		{
			header('location:forgotpass.php?pass=-1');
			exit();
		}
	
	?>
	
</body>
</html>