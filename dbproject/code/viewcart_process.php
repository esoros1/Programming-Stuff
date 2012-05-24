<?php

  	session_start();
	//the book is sent as an array through post. Decode it, then remove the selected amount of 
	//copies from the cart. If they want all of the copies removed, unset that book in the cart.
	
	//holds the index of books which need to be removed
	$removeBooks = array();
	
	foreach($_POST['Books'] as $index => $bookEncode)
	{
		$book = unserialize(urldecode($bookEncode));
		reset($_SESSION['cart']);
		//we want $cartBook to be a reference so it changes the original value
		foreach($_SESSION['cart']  as $cartIndex => &$cartBook)
		{
			if($cartBook['ISBN'] == $book['ISBN'])
			{
				$cartBook['qty'] = $_POST[$book['ISBN']];
				print_r($cartBook);
				if($cartBook['qty'] == 0)
				{
					$removeBooks[] = $cartIndex;
				}
			}
		}
	}
	
	//remove any books that have no copies left in the cart
	foreach($removeBooks as $index => $remove)
	{
		unset($_SESSION['cart'][$remove]);
	}
	
	header('location:userhome?success=1');
	exit();
?>