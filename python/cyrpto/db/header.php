<?php

	session_start();
	//display at the top
	echo '<div class="naviagation"><h1 class="top">That\'s Bargin! Books</h1></div>';
	if(isset($_SESSION['email']))
	{
		echo '<ul id="nav">';
		echo '<li><a href="userhome.php">Home</a></li>';
		echo '<li><a href="myorders.php">My Orders</a></li>';
		echo '<li><a href="viewaccount.php">My Account</a></li>';
		echo '<li><a href="contact.php">Contact</a></li>';
    	echo '<li><a href="logout.php">Logout</a></li>';
    	echo '<li><a href="viewcart.php"><img src="shopping-cart-icon.png" height="30" align="middle" /> </a></li></ul>';
	}
?>