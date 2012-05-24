<?php
	session_start();
	if(!$_SESSION['email'])
	{
		header("location:index");	
	}

?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8" />
<link rel="stylesheet" type="text/css" href="styles.css" />
<title>Untitled Document</title>
</head>

<body>
<?php require_once("header.php"); ?>
<table align="center" cellpadding="10">
<?php
	require_once("mysqli.php");
	global $db_obj;
	$email = $db_obj->real_escape_string($_SESSION['email']);
	$query = "SELECT * FROM `proj_orders` WHERE email = '$email' ";
	$result_obj = $db_obj->query($query);
	if($result_obj->num_rows != 0)
	{
		while( ($row = $result_obj->fetch_assoc()) )
		{
			echo "<tr>";
			echo '<td><a href="displayRecipt.php?orderID='.$row['order_ID'].'"> Order#: '.$row['order_ID'].'</a></td>';
			echo '</tr>';
		}
	}
	else
	{
		echo "<tr><td>You don't have any orders with us</td></tr>";
	}
?>
</table>
</body>
</html>