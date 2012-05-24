<?php

	session_start();
	require_once("mysqli.php");
	$currentpass = $db_obj->real_escape_string($_POST['currentpass']);
	$newpass = $db_obj->real_escape_string($_POST['newpass']);
	$email = $_SESSION['email'];	

	$query = "SELECT password_hash FROM proj_login WHERE email = '$email'";
	$result_obj = $db_obj->query($query);
	if($result_obj)
	{
		$row = $result_obj->fetch_assoc();
		if(md5($currentpass) == $row['password_hash'])
		{
			//TODO
			//still have to change the password
			$newpass = md5($newpass);
			$query = "UPDATE proj_login SET password_hash = '$newpass' WHERE email = '$email'";
			$result_obj = $db_obj->query($query);
			if($db_obj->affected_rows == 1)
			{
				header("location:changepassword.php?pass=1");
				exit();
			}
		
		}
		else
		{
			header("location:changepassword.php?pass=-1");
			exit();
		}
	}
	
?>