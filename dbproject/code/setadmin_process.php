<?php
	require_once("mysqli.php");
	
	$email = $db_obj->real_escape_string($_POST['email']);
	//first, check to see if the email is valid
	$query = "SELECT * FROM proj_customer WHERE email = '$email'";
	$result_obj = $db_obj->query($query);
	if($result_obj->num_rows == 1)
	{
		//try to insert the email into the admin table.
		//if it fails, the user is already admin.
		$query = "INSERT INTO proj_admin VALUES('$email')";
		$db_obj->query($query);
		if($db_obj->affected_rows == 1)
		{
			header('location:setadmin?err=0&email='.$email);
			exit();
		}
		else
		{
			header('location:setadmin?err=-2');
			exit();
		}
	}
	else
	{
		header('location:setadmin?err=-1');
		exit;
	}

?>