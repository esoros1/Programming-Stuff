<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8" />
<link rel="stylesheet" type="text/css" href="styles.css" />
<title>That's Bargain! Books</title>
</head>
<body>
	
<?php 
	
	require_once('header.php');	
	//if they aren't admin, just redirect them to the home page	
	redirectNotAdmin();
	
?>

	<div class="login-reg">
		<h1 class="form-text">Remove Book</h1>
		<form name="removebook" action="removebook_process.php" method="post">
			<p align="center">
				<label>ISBN</label>
				<input name="ISBN" type="text" size="15"/>
			</p>
			<p align="center">	
				<input type="submit" value="Remove"/>
			</p>
		</form>
	</div>

	<?php
	switch($_GET['success'])
	{	
		case 1:
		{	
			echo '<div class=success_box>Book Was Removed!</div>';
			break;
		}
		case -1:
		{	
			echo '<div class=clean-gray>That Book Has Already Been Removed.</br> Please Try Again</div>';
			break;
		}
	}	
?>

</body>
</html>