<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8" />
<link rel="stylesheet" type="text/css" href="styles.css" />
<title>That's Bargain! Books</title>
<script type="text/javascript" src="jquery.js"></script>          
 <script type="text/javascript">   
	$(document).ready(function() {
		
		$("#addbook").submit(function() { 
			
			$(".error_msg").hide();
			
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
			
			var pages = $("#pages").val();
			if(!isNumeric(pages))
			{
				$("#pages_err_msg").show();
				valid = false;
			} 
			
			var title = $("#title").val();
			if(title == "")
			{
				$("#title_err_msg").show();
				valid = false;
			}
			
			var author = $("#author").val();
			if(author == "")
			{
				$("#author_err_msg").show();
				valid = false;
			}
			
			var year = $("#year").val();
			if(year == "")
			{
				$("#year_err_msg").show();
				valid = false;
			}
			
			return valid;
		});
	
	});
 
 function validatePrice(str)
 {
 	return /^\d+.\d{2}$/.test(str);
 }
 
 function isNumeric(str)
 {
	return /^\d+$/.test(str);
 }
 
 //ISBN is either 13 or 10 digits. Make sure there are no dashes. Just numbers.
 function validateISBN(str)
 {
 	return ( /^\d{10}$/.test(str) ) || ( /^\d{13}$/.test(str) )
 }
 


</script>
</head>
<body>
	
	
<?php 

	require_once("header.php"); 
	redirectNotAdmin();
?>

<div class="login-reg1">
<form id="addbook" name="addbook" method="post" action="addbook_process.php" enctype="multipart/form-data">
	<h1 class="form-text">Add Book</h1>
	<table align="center" cellspacing="10">
		<tr>
		<td><label>ISBN</label></td>
		<td><input type="text" name="ISBN" id="ISBN"/></td>
		<td><p class="error_msg" id="ISBN_err_msg">Enter A Valid ISBN </br> 10 Or 13 Digits. No Dashes</p></td>
		</tr>
		
		<tr>
		<td><label>Title</label></td>
		<td><input type="text" name="title" id="title"/></td>
		<td><p class="error_msg" id="title_err_msg">Enter A Valid Title</p></td>
		</tr>
		
		<tr>
		<td><label>Price</label></td>
		<td><input type="text" name="price" id="price"/></td>
		<td><p class="error_msg" id="price_err_msg">Enter A Valid Price</p></td>
		</tr>
		
		<tr>
		<td><label>Book Cover</label></td>
		<td><input type="file" name="cover"/></td>
		</tr>
		
		<tr>
		<td><label># Pages</label></td>
		<td><input type="text" name="pages" id="pages"/></td>
		<td><p class="error_msg" id="pages_err_msg">Enter A Valid Number</p></td>
		</tr>
		
		<tr>
		<td><label>Publish Year</label></td>
		<td><input type="text" name="year" id="year"/></td>
		<td><p class="error_msg" id="year_err_msg">Enter A Valid Year</p></td>
		</tr>
		
		<tr>
		<td><label>Author</label></td>
		<td><input type="text" name="author" id="author"/></td>
		<td><p class="error_msg" id="author_err_msg">Enter A Valid Author</p></td>
		</tr>
		
		<td><label>Stock(optional)</label></td>
		<td><input type="text" name="stock"/></td>
	
	</table>	
	<p align="center">
		<input type="submit" value="Add Book"/>
	</p>
</form>
</div>	
<?php
	switch($_GET['err'])
	{	
		case 1:
		{	
			echo '<div class=success_box>The Book Was Successfully Added!</div>';
			break;
		}
		case -1:
		{	
			echo '<div class=clean-gray>That Book Is Already In The System.</br> Please Try Again</div>';
			break;
		}
		case -2:
		{
			echo '<div class=clean-gray>File Upload Must Be A jpg.</br> Please Try Again</div>';
		}
	
	}	
?>
</body>
</html>