<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8" />
<link rel="stylesheet" type="text/css" href="styles.css" />
<title>Untitled Document</title>
<script type="text/javascript" src="jquery.js"></script>          
 <script type="text/javascript">                                         
   $(document).ready(function() {
 		$("#changeuser").submit(function(){ 
			
			$(".error_msg").hide();
			var valid = true;
			var firstName = $("#firstname").val();
			if(firstName == "")
			{
				$("#first_error_msg").show();
				valid = false;
			}
			var lastName = $("#lastname").val();
			if(lastName == "")
			{
				$("#last_error_msg").show();
				valid = false;	
			}
			var address = $("#address").val();
			if(address == "")
			{
				$("#address_error_msg").show();
				valid = false;	
			}
			var phone = $("#phone").val();
			if(phone == "")
			{
				$("#phone_error_msg").show();
				valid = false;	
			}
			var city = $("#city").val();
			if(city == "")
			{
				$("#city_error_msg").show();
				valid = false;	
			}
			var state = $("#state").val();
			if(state.length != 2)
			{
				$("#state_error_msg").show();
				valid = false;	
			}
			var zip = $("#zip").val();
			if(zip == "")
			{
				$("#zip_error_msg").show();
				valid = false;	
			}
			return valid;
	});
 });                                  
</script>
</head>

<body>

<?php
	session_start();
	require_once("header.php");
?>
<form class="login-reg" method="post" action="viewaccount_process.php" id="changeuser">
<h1 class="form-text">Edit Account Information</h1>
<table align=center>	
            <tr>
            	<td><label>First Name:</label></td>
				<td><input type="text" id="firstname" name="firstname" value= <?php echo '"'.$_SESSION['firstname'].'"'; ?>/></td>
            	<td><p class="error_msg" id = "first_error_msg"> Please Enter a Valid First Name </p></td>
                </tr>
   			
            <tr>
           	 	<td><label>Last Name:</label></td>
    			<td><input type="text" id="lastname" name="lastname" value=<?php echo '"'.$_SESSION['lastname'].'"';?>/></td>
            	<td><p class="error_msg" id = "last_error_msg"> Please Enter a valid last name </p></td>
            </tr>
            	
          	<tr>
            	<td><label>Address:</label></td>
    			<td><input type="text" id="address" name="address" value=<?php echo '"'.$_SESSION['address_street'].'"';?>/></td>
                <td><p class="error_msg" id = "address_error_msg"> Please Enter a valid address</p></td>
            </tr>
       
            <tr>
            <td><label>Phone:</label></td>
    		<td><input type="text" id="phone" name="phone" value=<?php echo '"'.$_SESSION['phone'].'"';?>/></td>
            <td><p class="error_msg" id = "phone_error_msg"> Please Enter a valid phone number</p></td>
            </tr>       
         	
            <tr>
            <td><label>City:</label></td>
    		<td><input type="text" id="city" name="city" value=<?php echo '"'.$_SESSION['address_city'].'"';?>/></td>                            
            <td><p class="error_msg" id="city_error_msg"> Please Enter a valid city</p></td>
            </tr>
            
            <tr>
            <td><label>State:</label></td>
    		<td><input type="text" id="state" name="state" value=<?php echo '"'.$_SESSION['address_state'].'"';?> /></td>
            <td><p class="error_msg" id = "state_error_msg"> Please Enter a valid 2 digit abbreviation</p></td>
            </tr>
            
            <tr>
            <td><label>Zip:</label></td>
            <td><input type="text" id="zip" name="zip" value=<?php echo '"'.$_SESSION['address_zip'].'"'; ?>/></td>
            <td><p class="error_msg" id = "zip_error_msg"> Please Enter a valid zip</p></td>
            </tr>
             
            <tr>
            <td><a href="changepassword.php">Change Password?</a></td>
            <td><input type="submit" value="Submit" name="submit" class="submit" id="submit"/></td>
			</tr>
</table>
</form>
<?php
	switch($_GET['pass'])
	{	
		case 1:
			echo '<div class=success_box>Your Account Information Was Successfully Updated!</div>';
			break;
		case -1:
			echo '<div class=clean-gray>Something Wen\'t Wrong.</br> Please Try Again</div>';
			break;
	}	
?>
</body>
</html>