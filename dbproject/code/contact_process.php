<?php

	 require_once('mysqli.php');
	 $comment = $db_obj->real_escape_string($_POST['comments']);
	 
	 //do something with the email. Right now, I'm just going to redirect
	 //and say the message was successful. I may change this in the final version. 
	 header('location:contact.php?success=1');
	 exit();

?>