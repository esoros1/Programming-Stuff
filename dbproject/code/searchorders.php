<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8" />
<link rel="stylesheet" type="text/css" href="styles.css" />
<title>That's Bargain! Books</title>
</head>
<body>
	
	<?php require('header.php');  redirectNotAdmin(); ?>
	
	<div class="search_bar">
		<h1 class="form-text">Search Orders</h1>
		<form name="searchOrderId" action="searchorders_process.php" method="post">
			<table align="center">
        	<tr>
            	<td><label>Search:</label></td>
        		<td><input type="text" name ="search" size="15" /></td>
				<td><label>By:</label></td>
                <td><select name="search_type" size="1">
                	<option value="1">Order ID</option>
                 	<option value="2">Email</option>
                 </select>
                </td>
            	<td><input type="submit" value="Search" name="search_button" /> </td>
            </tr>
        	</table>
		</form>
	</div>

	<?php
	
	switch($_GET['success'])
	{
		case -1:
		{
			echo '<div class=clean-gray>That Order Is Not In The System.</br> Please Try Again</div>';
			break;
		}
		case -2:
		{
			echo '<div class=clean-gray>That Email Is Not In The System.</br> Please Try Again</div>';
			break;
		}
	
	}
	
	?>

</body>
</html>