<?php	
	session_start();
	
	require_once('globals.php');
	require_once('mysqli.php');
	//display at the top	
	echo '<div class="naviagation"><h1 class="top">That\'s Bargain! Books</h1></div>';
	//the current page being diplayed before the '.' . AKA no file extension and no get information.
	$currentURL = getBaseURL($_SERVER['REQUEST_URI']);
	//we want to display a navigation bar on all pages except for the index
	$email = $db_obj->real_escape_string($_SESSION['email']);
		
	if (! in_array($currentURL, $noNavBarArray) )
	{
		//the navigation bar for admin
		if(isset($_SESSION['admin']))
		{
			echo '<ul id="nav">';
			echo '<li><a href="userhome.php">Home</a></li>';
			echo '<li><a href="myorders.php?email='. $email .'&page=1&results=10">My Orders</a></li>';
			echo '<li><a href="viewaccount.php">My Account</a></li>';
			echo '<li><a href="admin.php">Admin</a></li>';
    		echo '<li><a href="logout.php">Logout</a></li>';
    		echo '<li><a href="viewcart.php"><img src="shopping-cart-icon.png" height="30" align="middle" /> </a></li></ul>';
		
		}
		//the navigation bar for logged in users
		else if(isset($_SESSION['email']))
		{
			echo '<ul id="nav">';
			echo '<li><a href="userhome.php">Home</a></li>';
			echo '<li><a href="myorders.php?email='. $email .'&page=1&results=10">My Orders</a></li>';
			echo '<li><a href="viewaccount.php">My Account</a></li>';
			echo '<li><a href="contact.php">Contact</a></li>';
    		echo '<li><a href="logout.php">Logout</a></li>';
    		echo '<li><a href="viewcart.php"><img src="shopping-cart-icon.png" height="30" align="middle" /> </a></li></ul>';
		}
		//the navigation bar for our guests
		else
		{
			echo '<ul id="nav">';
			echo '<li><p>Welcome Guest! It Seems That You Aren\'t Logged In Yet.</p></li>';
			echo '<li style="float:right;"><a href="viewcart.php"><img src="shopping-cart-icon.png" height="30" align="middle" /> </a></li>';
			echo '<li style="float:right;"><a href="index">Login</a></li>';
			echo '<li style="float:right;"><a href="newuser">Register<a></li>';
			echo '<li style="float:right"><a href="userhome.php">Home</a></li>';
			echo '</ul>';
		}

	}
?>