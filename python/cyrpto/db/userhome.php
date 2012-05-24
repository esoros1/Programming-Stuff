<?php
	session_start();
	if(!isset($_SESSION['email']))	
		header("location:index");
	
?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8" />
<link rel="stylesheet" type="text/css" href="styles.css" />
<title>Untitled Document</title>
</head>

<body>

<?php require_once("header.php"); ?>

<!-- search bar -->
<div class="search_bar">
	<form action="search.php" method="get">
    	<table>
        	<tr>
            	<td><label>Search:</label></td>
        		<td><input type="text" name ="search" size="50" /></td>
				<td><label>By:</label></td>
                <td><select name="search_type" size="1">
                	<option value="1">ISBN</option>
                    <option value="2">Author</option>
                    <option value="3">Title</option>
                 </select>
                </td>
            	<td><input type="submit" value="Search" name="search_button" /> </td>
            </tr>
        </table>
    </form>
</div>


</body>
</html>
