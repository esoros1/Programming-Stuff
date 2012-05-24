<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8" />
<link rel="stylesheet" type="text/css" href="styles.css" />
<title>That's Bargain! Books</title>
<script type="text/javascript" src="jquery.js"></script>          
 <script type="text/javascript">   

	 	$(document).ready(function() {
	 
		$("#comments").submit(function(){
		
			
		
		});
		 
	});

</script>

</head>
<body>
<?php  require('header.php'); ?>
<form name="comments" id="comments" action="contact_process.php" method="post" onsubmit="test()">	
	<div align="center">
		<p>Have Any Comments, Questions, Or Concerns?</p>
		<p>They Will Be Emailed To Us, and Someone Will Get Back To You Shortly</p>
		<TEXTAREA NAME="comments" COLS=40 ROWS=6></TEXTAREA></br>
		<input type="submit" value="Send"/>
	</div>
	
	<?php
	if(isset($_GET['success']))
	{
		echo '<div class=success_box id="messagesent">Email Sent!</br>We Will Get Back To You Shortly</div>';
	}
	?>


</form>
</body>
</html>