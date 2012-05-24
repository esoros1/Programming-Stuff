<?php
	require_once("mysqli.php");
	session_start();
	
	global $db_obj;
	$email = $_SESSION['email'];
	$firstname = $db_obj->real_escape_string($_POST['firstname']);
	$lastname = $db_obj->real_escape_string($_POST['lastname']);
	$address = $db_obj->real_escape_string($_POST['address']);
	$phone = $db_obj->real_escape_string($_POST['phone']);
	$city = $db_obj->real_escape_string($_POST['city']);
	$state = $db_obj->real_escape_string($_POST['state']);
	$zip = $db_obj->real_escape_string($_POST['zip']);

	$query = "UPDATE proj_customer SET firstname = '$firstname', lastname = '$lastname', ";
	$query .= "address_street = '$address', phone = '$phone', address_city = '$city', address_state = '$state', ";
	$query .= "address_zip = '$zip' WHERE email = '$email'";
	
	$result_obj = $db_obj->query($query);
	if($result_obj)
	{
		//update the session information.
		$_SESSION['firstname'] = $firstname;
		$_SESSION['lastname'] = $lastname;
		$_SESSION['address_street'] = $address;
		$_SESSION['address_city'] = $city;
		$_SESSION['address_state'] = $state;
		$_SESSION['address_zip'] = $zip;
		$_SESSION['phone'] = $phone;

		header('location:viewaccount?pass=1');
		exit();
	}
	else
	{
		header('location:viewaccount?pass=-1');
		exit();
	}
?>