<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8" />
<link rel="stylesheet" type="text/css" href="styles.css" />
<title>Untitled Document</title>
</head>

<body>
<?php
	require("header.php");
?>
<!-- Login Box -->
<form action="login.php" method="post" class="login-reg">
        <h1 class="form-text">Login</h1>
        <table align=center>
        <tr>
        	<td><label>Email:</label></td>
        	<td><input type="text" name="email" /></td>
        </tr>
 		<tr>       
        	<td><label>Password:</label></td>
        	<td><input type="password" name="password"  /></td>
        </tr>    	
        <tr>       
        	<td><a href="forgotpass.php">Forgot Password?</a></td>
            <td><input type="submit" value="Login" name="submit" class="submit" /></td>
            <td><a href="newuser.html">New User?</a></td>
       </tr>     
	   </table>
</form>

<?php
	session_start();
	if($_GET['pass'] == -1)
		echo '<div class="clean-gray">Incorrect Username/Password Combination. Please Try Again</div>';
	if($_GET['pass'] == 1)	
		echo '<div class="success_box">Thank You For Your Registration!</br>'.$_SESSION['firstname'].' '.$_SESSION['lastname'].'</div>';
	

?>


</body>
</html>