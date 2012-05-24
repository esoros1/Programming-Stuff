<?php
	session_start();
	if(!$_SESSION['email'])
	{
		header("location:index");	
	}

?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8" />
<link rel="stylesheet" type="text/css" href="styles.css" />
<title>That's Bargain! Books</title>

<script type="text/javascript" src="jquery.js"></script>          
<script type="text/javascript">               

//hacked together some javascript that will reload the page when the user
//changes the results per page
function resultsPerPage()
{
	var results = document.getElementsByName("results")[0].value;
	
	var getParts = window.location.search.split("&");
	var newURL = "";
	for(var i = 0; i < getParts.length; ++i)
	{
		var getPart = getParts[i];
		if(getPart.substr(0,7) == "results")
		{	
			newURL += getPart.substr(0,7) + "=" + results + "&";
			
		}
		else
		{
			newURL += getPart + "&";
		}
	}
	
	window.location = "myorders.php" + newURL;
}

</script>

</head>

<body>
<?php 
	require_once("header.php"); 

		//only admins and the user can see the past order history. The email is passed in as a get parameter. 
		//just make sure the email in the get and the email in the session match. Or that they are an admin
	if($_GET['email'] == $_SESSION['email'] || isset($_SESSION['admin']) )
	{
		require_once("mysqli.php");
		global $db_obj;
		$email = $db_obj->real_escape_string($_GET['email']);
		$maxResults = $_GET['max_results'];
		
		//we need to get the max number of orders for displaying orders on different pages.
		//if maxResults is not set as a GET variable, calculate it and see if we need to display the next page.
		if(!isset($maxResults))
		{	
			$query = "SELECT * FROM `proj_orders` WHERE email = '$email' ";
			$result_obj = $db_obj->query($query);
			$maxResults = $result_obj->num_rows;
		}
		
		//now query the results for the page
		$query = "SELECT * FROM proj_orders WHERE email = '$email' ";
		$query .= 'LIMIT ' . ( ($_GET['page'] - 1) * $_GET['results'] ) . ', ' . $_GET['results'];
		$result_obj = $db_obj->query($query);
		
		if($result_obj->num_rows != 0)
		{
			echo '<div class="login-reg">';
			echo '<h1 class="form-text">Past Orders</h1>';
			echo '<table align="center" cellpadding="10">';
			while( ($row = $result_obj->fetch_assoc()) )
			{
				echo "<tr>";
				echo '<td><a href="displayRecipt.php?orderID='.$row['order_ID'].'"> Order#: '.$row['order_ID'].'</a></td>';
				echo '<td>'. date($row['order_date'])  .'</td>';
				echo '</tr>';
			}
			echo '</table>';
			echo '</div>';
			echo '</br>';
			
			//don't display the previous page on the first page
			echo '<div align=center>';
			if($_GET['page'] > 1)
			{
				$previousPage = sprintf('myorders.php?email=%s&page=%s&results=%s&max_results=%s',
										$email, $_GET['page']-1, $_GET['results'], $maxResults);
				
				echo '<a href='. $previousPage .'>Previous Page</a>';
			}
			
			//make sure that we have enough results to go onto the next part
		    if( $maxResults > $_GET['page'] * $_GET['results']  )
			{
				
				$nextPage = sprintf('myorders.php?email=%s&page=%s&results=%s&max_results=%s',
										$email, $_GET['page']+1, $_GET['results'], $maxResults);
				echo '<a href='. $nextPage .'> Next Page</a> ';
			}
			
			echo '<label>Results Per Page</label>';
			echo selectBox('results', 10 , "resultsPerPage", $_GET['results']);
			echo '</div>';
		}
		else
		{
			echo '<p align="center"><td>No Orders On File</p>';
		}
	}
	//otherwise they don't have permission to view this page, and we should redirect them to the home page
	else
	{
		header('location:userhome');
		exit();
	}
?>
</table>
</body>
</html>