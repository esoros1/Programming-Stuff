
<?php 
	require_once("mysqli.php");
	
	//authenticates a user. Also checks to see if they are admin or not.  
	//email is the email address and pass is the password
	//the password is stored as an md5 hash. 
	//return "ADMIN" if they are an admin, "user" if they are a user, and false otherwise. 
	function authenticate_user($email, $pass)
	{
		global $db_obj;	
		$email = $db_obj->escape_string($email);
		$pass = md5($db_obj->escape_string($pass));
		
		$query = "SELECT * FROM proj_login WHERE email ='$email' AND password_hash = '$pass'";  
	
		if ( ($result = $db_obj->query($query)) && $result->num_rows == 1)
		{
			//check to see if admin
			$query = "SELECT * FROM proj_admin WHERE email = '$email'";
			
			if( ($result = $db_obj->query($query)) && $result->num_rows == 1)
			{	
				echo $query;
				return "ADMIN";
			}
			else
				return "USER";
		}
		
		else
			return FALSE;
	}
	
?>

