<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8" />
<link rel="stylesheet" type="text/css" href="styles.css" />
<title>That's Bargain! Books</title>
<script type="text/javascript" src="jquery.js"></script>          
<script type="text/javascript"> 
</script>

</head>
<body>
		
<?php require_once("header.php"); 	redirectNotAdmin(); ?>

<div class="login-reg">
<form name="setAdmin" id="setAdmin" method="post" action="setadmin_process.php">
	<h1 class="form-text">Upgrade User</br> To Admin</h1>
	<table align="center" style="margin-left:auto;margin-right:auto">
		<tr>
		<td><label>Email</label></td>
		<td><input type="text" name="email" id="email"/></td>
		<td><p class="error_msg" id="email_err_msg">Please Enter A Valid Email</p></td>
		</tr>
	</table>	
	<p align="center">
		<input type="submit" value="Update"/>
	</p>
	</div>
</form>
</div>
	

<?php
	if(isset($_GET['err']))
	{	
		switch($_GET['err'])
		{	
			case 0:
			{	
				echo '<div class=success_box>'. $_GET['email'] . ' Is Now An Admin!</div>';
				break;
			}
			case -1:
			{	
				echo '<div class=clean-gray>That User Is Not In The System.</br> Please Try Again</div>';
				break;
			}
			case -2:
			{
				echo '<div class=clean-gray>That User Is Already Admin</div>';
				break;
			}	
		}	

	}
?>


	
	