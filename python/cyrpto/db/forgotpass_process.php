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
		require_once("mysqli.php");
		//check to see if the email is in the system or not
		//returns the email if it is in the system. 
		//returns false otherwise. 
		function isRegisteredEmail($email)
		{
			global $db_obj;
			
			$query = "SELECT * FROM proj_customer WHERE email = '$email'";
			$result_obj = $db_obj->query($query);
			
			if($result_obj->num_rows == 1)
			{
				$assoc = $result_obj->fetch_assoc();
				return $assoc['email'];
			}
			else
			{
				return FALSE;
			}
		}
	
		//updates a users password in the system. 
		//returns true on sucessful update, false otherwise
		function changePassword($email, $pass)
		{
			global $db_obj;
			
			$pass = md5($pass);
			$query = "UPDATE proj_login SET password_hash = '$pass' WHERE email = '$email'";
			
			if( ($result_obj = $db_obj->query($query)) )
			{
				return TRUE;	
			}
			else
			{
				return FALSE;
			}
		}
		
			
		$isRegistered = isRegisteredEmail($_POST['email']);
		if($isRegistered['email'])
		{
			//send them an email telling them that there password has been reset
			$message = "Your password has been reset to 'password' (without quotes)\n";
			$message .= "Please login and change your password ASAP.";
			
			mail($_POST['email'],"Password Reset",$message);
			echo "An email has been sent to your email address.";
		}
		else
			echo "I'm sorry, that email address is not in our system";
	
	?>
	
</body>
</html>