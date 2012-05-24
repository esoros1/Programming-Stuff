<?php
	session_start();
	//if(!isset($_SESSION['email']))	
	//	header("location:index");
	
	class editCart
	{
		const SUCCESS  = 1;
		CONST FAIL = -1;
	}
	
	class addToCart
	{
		const SUCCESS = 2;
		const FAIL = -2;
	}


?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8" />
<link rel="stylesheet" type="text/css" href="styles.css" />
<title>That's Bargain! Books</title>
</head>

<body>

<?php require_once("header.php"); ?>

<!-- search bar -->
<div class="search_bar">
	<form action="search.php" method="get">
    	<input type="hidden" name="page" value="1">
    	<input type="hidden" name="results" value="10">
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

<?php
		
	switch ($_GET['success'])
	{
		case editCart::SUCCESS:
		{
		
			echo '<div class="success_box" >Your Shopping Cart Has Been Successfully Updated</div>';
			break;
		}
		case editCart::FAIL:
		{
			break;
		}
		case addToCart::SUCCESS:
		{
			echo '<div class="success_box" >Items Added To Cart!</div>';
			break;
		}
	
	}

?>

</body>
</html>
