<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8" />
<link rel="stylesheet" type="text/css" href="styles.css" />
<title>That's Bargain! Books</title>
<script type="text/javascript" src="jquery.js"></script>          
<script type="text/javascript"> 
$(document).ready(function() {
 	 		 		 		
 		$(".error_msg").hide();
 		
 		$("#changeprice").submit(function(){ 

			var valid = true;
			
			var ISBN = $("#ISBN").val();
			if(!validateISBN(ISBN))
			{
				$("#ISBN_err_msg").show();
				valid = false;
			}
		
			var price = $("#price").val();
			if(!validatePrice(price))
			{
				$("#price_err_msg").show();
				valid = false;
			}
			
			return valid;
		
		});
	});
 
 //ISBN is either 13 or 10 digits. Make sure there are no dashes. Just numbers.
 function validateISBN(str)
 {
 	return ( /^\d{10}$/.test(str) ) || ( /^\d{13}$/.test(str) )
 }
 
 function validatePrice(str)
 {
 	return /^\d+.\d{2}$/.test(str);
 }
 

</script>

</head>
<body>
	
<?php 
	
	require_once('header.php');	
	//if they aren't admin, just redirect them to the home page	
	redirectNotAdmin();
	
?>

	<div class="login-reg">
		<h1 class="form-text">Change Prices</h1>
		<form name="changePrice"  id="changeprice" action="changeprice_process.php" method="post">
			<table align="center">
				<tr>
					<td><label>ISBN</label></td>
					<td><input name="ISBN" id="ISBN" type="text" size="15"/></td>
					<td><p class="error_msg" id="ISBN_err_msg">Enter A Valid ISBN </br> 10 Or 13 Digits Without Dashes</p></td>
				</tr>
				
				<tr>
					<td><label>Price $</label></td>
					<td><input name="price" id="price" type="text" size="15"/></td>
					<td><p class="error_msg" id="price_err_msg">Enter A Valid Price </br> xx.xx </p></td>
				</tr>
			</table>	
			
			<p align="center">	
				<input type="submit" value="Update"/>
			</p>
		</form>
	</div>

	<?php
	switch($_GET['success'])
	{	
		case 1:
		{	
			echo '<div class=success_box>Price Change Was Successfull</div>';
			break;
		}
		case -1:
		{	
			echo '<div class=clean-gray>That Book Is Not In The System.</br> Please Try Again</div>';
			break;
		}
	}	
?>

</body>
</html>