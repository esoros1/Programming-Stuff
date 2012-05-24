<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8" />
<link rel="stylesheet" type="text/css" href="styles.css" />
<title>That's Bargain! Books</title>
</head>
<body>
<?php require('header.php');  	redirectNotAdmin(); ?>
	
	<!-- search bar -->
<div class="search_bar">
	<h1 class="form-text">Customer Search</h1>
	<form action="customersearch_results.php" method="get">
    	<input type="hidden" name="page" value="1">
    	<input type="hidden" name="results" value="10">
    	<table align="center">
        	<tr>
            	<td><label>Search:</label></td>
        		<td><input type="text" name ="search" size="30" /></td>
				<td><label>By:</label></td>
                <td><select name="search_type" size="1">
                	<option value="1">Email</option>
                 	<option value="2">Name</option>
                 </select>
                </td>
            	<td><input type="submit" value="Search" name="search_button" /> </td>
            </tr>
        </table>
    </form>
</div>


</body>
</html>