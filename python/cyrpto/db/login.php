<?php

	require_once("user_authentication.php");
	require_once("mysqli.php");
	$login = authenticate_user($_POST['email'], $_POST['password']);
	if ($login)
	{
		//save the user information in the session.
		session_start();
		global $db_obj;
		
		$email = $db_obj->real_escape_string($_POST['email']);
		$query = "SELECT * FROM proj_customer WHERE email = '$email'";
		$resut_obj = $db_obj->query($query);
		$row = $resut_obj->fetch_assoc();
		
		if($row)
		{
			foreach($row as $header => $value)
			{
				$_SESSION[$header] = $value;	
			}
		}
		if($login == "ADMIN")
		{
			
		}
		else
		{
			header("location:userhome.php");	
			exit();
		}
	}

?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8" />
<link rel="stylesheet" type="text/css" href="styles.css" />
<title>Untitled Document</title>
</head>

<!-- Bar across the rop -->
<div class="naviagation">
	<h1 class="top">That's Bullshit! Books</h1>
</div>

<?php	
	if(!$login)
	{
		header("location:index.php?pass=-1");	
	}

?>
<body>
</body>
</html>