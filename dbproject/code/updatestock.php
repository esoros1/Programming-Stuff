  <!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8" />
<link rel="stylesheet" type="text/css" href="styles.css" />
<title>That's Bargain! Books</title>
<script type="text/javascript" src="jquery.js"></script>          
<script type="text/javascript"> 
   $(document).ready(function() {
 		$("#updateStock").submit(function(){ 
		$(".error_msg").hide();
		var valid = true;
		var ISBN = $("#ISBN").val();
		if(ISBN == "")
		{
			valid = false;
			$("#ISBN_err_msg").show();
		}
		
		var qty = $("#qty").val();
		if(qty == "")
		{
			valid = false;
			$("#qty_err_msg").show();
		}
		
		return valid;
	});
 }); 
</script>

</head>
<body>
		
<?php require_once("header.php"); ?>

<div class="login-reg">
<form name="updateStock" id="updateStock" method="post" action="updatestock_process.php">
	<h1 class="form-text">Update Stock</h1>
	<table align="center" style="margin-left:auto;margin-right:auto">
		<tr>
		<td><label>ISBN</label></td>
		<td><input type="text" name="ISBN" id="ISBN"/></td>
		<td><p class="error_msg" id="ISBN_err_msg">Please Enter A Valid ISBN</p></td>
		</tr>
		<tr>
		<td><label>Qty</label></td>
		<td><input type="text" name="qty" id="qty"/></td>
		<td><p class="error_msg" id="qty_err_msg">Please Enter A Valid Quantity</p></td>
		</tr>
	</table>	
	<p align="center">
		<input type="submit" value="Update"/>
	</p>
	</div>
</form>
</div>
	

<?php
	switch($_GET['pass'])
	{	
		case 1:
			echo '<div class=success_box>Stock Was Successfully Updated!</div>';
			break;
		case -1:
			echo '<div class=clean-gray>That Book Is Not In The System.</br> Please Try Again</div>';
			break;
	}	
?>


	
	
</body>