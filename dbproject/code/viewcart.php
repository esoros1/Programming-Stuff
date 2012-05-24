<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8" />
<link rel="stylesheet" type="text/css" href="styles.css" />
<title>That's Bargain! Books</title>
</head>
<body>
<?php
	
	
	require("globals.php");
		
	session_start();
	require_once("header.php");
	if(!$_SESSION['cart'] || count($_SESSION['cart']) == 0)
	{
		echo '<p align=center>Your Shopping Cart Is Empty</p>';
	}
	else
	{
		
?>
		<form method="post" action="viewcart_process.php" name="editcart">
		<div class="book_display">
		<h1 class="form-text">Shopping Cart</h1>
<?php		
		echo '<table cellpadding=10 align=center>';
		foreach($_SESSION['cart'] as $ISBN => $book)	
		{	
			displayBookTable($book['title'],
							 $book['ISBN'],
							 $book['author'],		
							 $book['pages'],
							 $book['year'],
							 $book['price'],
							 $book['qty'],
							 selectBox($book['ISBN'],$book['qty'],NULL,$book['qty'])
							);	
		}
		echo '</table>';
		echo '</div>';
		$subtotal = subtotal();
		$taxes = ($subtotal + 9.99) * .10;
		$total = $subtotal + $taxes + 9.99;
		echo '<p align=center>Subtotal: $'.$subtotal.' Shipping & Handeling: $9.99 Taxes: $'.number_format($taxes,2).' Total: $'. 																										 number_format($total,2) .'</p>';
	
	
?>		<p align=center><input type=submit value="Edit Cart"/> <a href="checkout">Checkout</a></p>
		</form>
	
<?php
	}
?>

</body>
</html>