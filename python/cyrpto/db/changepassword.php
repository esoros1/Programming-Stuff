<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8" />
<link rel="stylesheet" type="text/css" href="styles.css" />
<title>Untitled Document</title>
<script type="text/javascript" src="jquery.js"></script>          
 <script type="text/javascript">                                         
   $(document).ready(function() {
 		$("#updatepass").submit(function(){ 
			
			$(".error_msg").hide();
			var valid = true;
			var currentpass = $("#currentpass").val();
			if(currentpass == "")
			{
				$("#currentpass_err").show();
				valid = false;
			}
			var newpass = $("#newpass").val();
			if(newpass == "")
			{
				$("#newpass_err").show();
				valid = false;
				
			}
			var confirmNewPass = $("#confirm_new_pass").val();
			if(confirmNewPass == "")
			{
				$("#confirm_new_pass_err").show();
				valid = false;
			}
			else if(newpass == "" || confirmNewPass != newpass)
			{
				
				$("#passconfirm_errbox").show();
				valid = false;
			}
			return valid;
	});
 });                                  
</script>
</head>

<body>
	<?php require_once("header.php"); ?>	
	<!-- password change box -->
	<div class="login-reg"/>
		<h1 class="form-text">Password Change</h1>
		<form method="post" action="changepassword_process.php" id="updatepass"/>
			<table align="center">
				
				<tr>
				<td><label>Current Password:</label></td>
				<td><input type="password" id="currentpass" name="currentpass"/></td>
				<td><p class="error_msg" id="currentpass_err">Please Enter A Valid Password</p></td>
				</tr>
				<tr>
				<td><label>New Password:</label></td>
				<td><input type="password" id="newpass" name="newpass"/></td>
				<td><p class="error_msg" id="newpass_err">Please Enter A Valid Password</p></td>
				<td><p class="error_msg" id="passconfirm_err">Those Passwords Didn't Match</p></td>
				</tr>
				<tr>
				<td><label>Confirm New Password:</label></td>
				<td><input type="password" id="confirm_new_pass" name="confirm_new_pass"/></td>
				<td><p class="error_msg" id="confirm_new_pass_err">Please Enter A Valid Password</p></td>
				</tr>
			</table>	
				<div style="margin-left:auto;margin-right:auto;">
				<input type="submit"/>
				</div>
		</form>
	</div>

	<div class="clean-gray" style="display:none" id="passconfirm_errbox">Those Passwords Don't Match.</div>'

<?php
	switch($_GET['pass'])
	{
		case 1:
			echo '<div class="success_box">Password Change Successful</div>';
			break;
		case -1:
			echo '<div class="clean-gray">That Password Was Incorrect. </br>Please Try Again</div>';	
			break;
	}
?>

</body>
</html>