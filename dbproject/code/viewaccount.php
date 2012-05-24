<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8" />
<link rel="stylesheet" type="text/css" href="styles.css" />
<title>That's Bargain! Books</title>
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
			if(!validatePhoneNumber(phone))
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
			
			
			var zip = $("#zip").val();
			if(!validateZipCode(zip))
			{
				$("#zip_error_msg").show();
				valid = false;	
			}		

			return valid;
	});
 });                                   
 
 //make sure that the string only contains letters using regular expressions
 function isAlpha(str)
 {
 	return /^[a-zA-Z()]+$/.test(str)
 }
 
 //make sure that the phone number is of the form xxx-xxx-xxxx
 function validatePhoneNumber(str)
 {
 	return /^\d{3}-\d{3}-\d{4}$/.test(str);
 }
 
 //make sure that the email address has the correct form 
 function validateEmailAddress(str)
 {
 	return /^[a-zA-Z0-9]+@[a-zA-Z0-9]+.[a-zA-Z0-9]+$/.test(str);
 }
 
 //make sure that the zip code is 5 digits long
 function validateZipCode(str)
 {
 	return /^\d{5}$/.test(str);
 }
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
    		<td><select name="state">
        			<option value="AL"<?php  if($_SESSION['address_state'] == "AL") echo " selected=YES";?>>Alabama</option>
					<option value="AK"<?php  if($_SESSION['address_state'] == "AK") echo " selected=YES";?>>Alaska</option>
					<option value="AZ"<?php  if($_SESSION['address_state'] == "AZ") echo " selected=YES";?>>Arizona</option>
					<option value="AR"<?php  if($_SESSION['address_state'] == "AR") echo " selected=YES";?>>Arkansas</option>
					<option value="CA"<?php  if($_SESSION['address_state'] == "CA") echo " selected=YES";?>>California</option>
					<option value="CO"<?php  if($_SESSION['address_state'] == "CO") echo " selected=YES";?>>Colorado</option>
					<option value="CT"<?php  if($_SESSION['address_state'] == "CT") echo " selected=YES";?>>Connecticut</option>
					<option value="DE"<?php  if($_SESSION['address_state'] == "DE") echo " selected=YES";?>>Delaware</option>
					<option value="DC"<?php  if($_SESSION['address_state'] == "DC") echo " selected=YES";?>>District of Columbia</option>
					<option value="FL"<?php  if($_SESSION['address_state'] == "FL") echo " selected=YES";?>>Florida</option>
					<option value="GA"<?php  if($_SESSION['address_state'] == "GA") echo " selected=YES";?>>Georgia</option>
					<option value="HI"<?php  if($_SESSION['address_state'] == "HI") echo " selected=YES";?>>Hawaii</option>
					<option value="ID"<?php  if($_SESSION['address_state'] == "ID") echo " selected=YES";?>>Idaho</option>
					<option value="IL"<?php  if($_SESSION['address_state'] == "IL") echo " selected=YES";?>>Illinois</option>
					<option value="IN"<?php  if($_SESSION['address_state'] == "IN") echo " selected=YES";?>>Indiana</option>
					<option value="IA"<?php  if($_SESSION['address_state'] == "IA") echo " selected=YES";?>>Iowa</option>
					<option value="KS"<?php  if($_SESSION['address_state'] == "KS") echo " selected=YES";?>>Kansas</option>
					<option value="KY"<?php  if($_SESSION['address_state'] == "KY") echo " selected=YES";?>>Kentucky</option>
					<option value="LA"<?php  if($_SESSION['address_state'] == "LA") echo " selected=YES";?>>Louisiana</option>
					<option value="ME"<?php  if($_SESSION['address_state'] == "ME") echo " selected=YES";?>>Maine</option>
					<option value="MD"<?php  if($_SESSION['address_state'] == "MD") echo " selected=YES";?>>Maryland</option>
					<option value="MA"<?php  if($_SESSION['address_state'] == "MA") echo " selected=YES";?>>Massachusetts</option>
					<option value="MI"<?php  if($_SESSION['address_state'] == "MI") echo " selected=YES";?>>Michigan</option>
					<option value="MN"<?php  if($_SESSION['address_state'] == "MN") echo " selected=YES";?>>Minnesota</option>
					<option value="MS"<?php  if($_SESSION['address_state'] == "MS") echo " selected=YES";?>>Mississippi</option>
					<option value="MO"<?php  if($_SESSION['address_state'] == "MO") echo " selected=YES";?>>Missouri</option>
					<option value="MT"<?php  if($_SESSION['address_state'] == "MT") echo " selected=YES";?>>Montana</option>
					<option value="NE"<?php  if($_SESSION['address_state'] == "NE") echo " selected=YES";?>>Nebraska</option>
					<option value="NV"<?php  if($_SESSION['address_state'] == "NV") echo " selected=YES";?>>Nevada</option>
					<option value="NH"<?php  if($_SESSION['address_state'] == "NH") echo " selected=YES";?>>New Hampshire</option>
					<option value="NJ"<?php  if($_SESSION['address_state'] == "NJ") echo " selected=YES";?>>New Jersey</option>
					<option value="NM"<?php  if($_SESSION['address_state'] == "NM") echo " selected=YES";?>>New Mexico</option>
					<option value="NY"<?php  if($_SESSION['address_state'] == "NY") echo " selected=YES";?>>New York</option>
					<option value="NC"<?php  if($_SESSION['address_state'] == "NC") echo " selected=YES";?>>North Carolina</option>
					<option value="ND"<?php  if($_SESSION['address_state'] == "ND") echo " selected=YES";?>>North Dakota</option>
					<option value="OH"<?php  if($_SESSION['address_state'] == "OH") echo " selected=YES";?>>Ohio</option>
					<option value="OK"<?php  if($_SESSION['address_state'] == "OK") echo " selected=YES";?>>Oklahoma</option>
					<option value="OR"<?php  if($_SESSION['address_state'] == "OR") echo " selected=YES";?>>Oregon</option>
					<option value="PA"<?php  if($_SESSION['address_state'] == "PA") echo " selected=YES";?>>Pennsylvania</option>
					<option value="RI"<?php  if($_SESSION['address_state'] == "RI") echo " selected=YES";?>>Rhode Island</option>
					<option value="SC"<?php  if($_SESSION['address_state'] == "SC") echo " selected=YES";?>>South Carolina</option>
					<option value="SD"<?php  if($_SESSION['address_state'] == "SD") echo " selected=YES";?>>South Dakota</option>
					<option value="TN"<?php  if($_SESSION['address_state'] == "TN") echo " selected=YES";?>>Tennessee</option>
					<option value="TX"<?php  if($_SESSION['address_state'] == "TX") echo " selected=YES";?>>Texas</option>
					<option value="UT"<?php  if($_SESSION['address_state'] == "UT") echo " selected=YES";?>>Utah</option>
					<option value="VT"<?php  if($_SESSION['address_state'] == "VT") echo " selected=YES";?>>Vermont</option>
					<option value="VA"<?php  if($_SESSION['address_state'] == "VA") echo " selected=YES";?>>Virginia</option>
					<option value="WA"<?php  if($_SESSION['address_state'] == "WA") echo " selected=YES";?>>Washington</option>
					<option value="WV"<?php  if($_SESSION['address_state'] == "WV") echo " selected=YES";?>>West Virginia</option>
					<option value="WI"<?php  if($_SESSION['address_state'] == "WI") echo " selected=YES";?>>Wisconsin</option>
					<option value="WY"<?php  if($_SESSION['address_state'] == "WY") echo " selected=YES";?>>Wyoming</option>
			</select></td>
            </tr>
            
            <tr>
            	<td><label>Zip:</label></td>
            	<td><input type="text" id="zip" name="zip" value=<?php echo '"'.$_SESSION['address_zip'].'"'; ?>/></td>
            	<td><p class="error_msg" id = "zip_error_msg"> Please Enter a valid zip</p></td>
            </tr>
             
            <tr>
           		<td><a href="changepassword.php">Change Password</a></td>
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