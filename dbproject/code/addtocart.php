<?php
	
	session_start();
	//add the books the selected to the cart, which is an associative array that maps
	//the ISBN to a book to an array that contains information about the book.
	if( !isset($_SESSION['cart']) )
	{
		$_SESSION['cart'] = array();
	
	}	
	
	//look to see if the current book is already in side the cart. We don't need two copies of the same product in the cart 
	foreach($_POST['Books'] as $index => $bookEncode)
	{
		$book = unserialize(urldecode($bookEncode));
		$book['qty'] = $_POST[$book['ISBN']];
		//if the book is in the cart, then just change the quantity
		if($_SESSION['cart'][$book['ISBN']])
		{
			//reference to the book in the cart.
			$bookRef = &$_SESSION['cart'][$book['ISBN']];
			$bookRef['qty'] += $book['qty'];
		}
		else
		{
			//add a new map
			$_SESSION['cart'][$book['ISBN']] = $book;
		}
	}
	
	header('location:userhome?success=2');

?>