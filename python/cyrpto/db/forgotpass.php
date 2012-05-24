<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8" />
<link rel="stylesheet" type="text/css" href="styles.css" />
<title>Untitled Document</title>
</head>

<body>
<?php require("header.php"); ?>

<!-- reset password box -->
<form action="forgotpass_process.php" method="post" class="login-reg">
        <h1 class="form-text">Password Reset</h1>
        <p>Enter your email, and a new password will be sent to it</p>
        <table border="0">
        <tr>
        	<td><label>Email:</label></td>
        	<td><input type="text" name="email" /></td>
        </tr>    	
        <tr>       
            <td><input type="submit" value="Reset" name="submit" class="submit" /></td>
       </tr>     
</table>
</form>

<?php
	switch($_GET['pass'])
	{
		case -1:
			echo '<div class="clean-gray">That Email Address Was Not In Our System</br>Please Try Again</div>';
			break;
		case 1:
			echo '<div class="success_box">A New Password Was Sent To Your Email</div>';
			break;
	}
?>

</body>
</html>