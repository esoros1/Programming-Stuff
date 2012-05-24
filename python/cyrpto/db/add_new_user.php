<?php

	require_once("mysqli.php");	

	
	//this function adds a user to the database. 
	//will return true on a successful insert, and false otherwise. 
	function addNewUser($firstname, $lastname, $email, $address,
						$phone, $city, $state, $zip, $password)
	{	
	
		global $db_obj;
		$firstname = $db_obj->escape_string($firstname);
		$lastname = $db_obj->escape_string($lastname);
		$email = $db_obj->escape_string($email);
		$address = $db_obj->escape_string($address);
		$phone = $db_obj->escape_string($phone);
		$city = $db_obj->escape_string($city);
		$state = $db_obj->escape_string($state);
		$zip = $db_obj->escape_string($zip);
		$password = md5($db_obj->escape_string($password));
		
		$query = "INSERT INTO proj_customer VALUES('$firstname','$lastname','$address',
			'$city','$state','$zip','$phone','$email')";
			
		//exit if the first insert failed.
		if(!($result_obj = $db_obj->query($query)))
			return FALSE;

		//now we have to add the password_hash to the databse as well. 
		$query = "INSERT INTO proj_login VALUES('$email','$password')";
		
		$result_obj = $db_obj->query($query);
		if($result_obj)
		{
			return TRUE;	
		}
		else
			return FALSE;
	
	}

?>