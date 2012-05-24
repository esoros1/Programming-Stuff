<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8" />
<link rel="stylesheet" type="text/css" href="styles.css" />
<title>That's Bargain! Books</title>
<script>

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
		//we want to set the results back to the beginning. 
		else if(getPart.substr(0,5) == "?page")
		{	
			newURL += getPart.substr(0,5) + "=" + 1 + "&";
		}
		else
		{
			newURL += getPart + "&";
		}
	}
	
	window.location = "customersearch_results.php" + newURL;
}

</script>

</head>
<body>
<?php
	
	session_start();
	if(!isset($_SESSION['admin']))
	{
		header('location:userhome');
		exit();
	}	
	
	//enum to make the switch statement easier to read
	class customerSearchType
	{
		const EMAIL = 1;
		const NAME = 2;
	}
	
	require_once('mysqli.php');
	require('header.php');
	
	//get the maximum number of results so we know if to display the next page link or not.
	$maxResults = $_GET['max_results'];
	
	//what did the user want to search by?
	switch($_GET['search_type'])
	{
		case customerSearchType::EMAIL :
		{
			$email = $db_obj->real_escape_string($_GET['search']);
			$query = "SELECT * FROM proj_customer WHERE email = '$email'";
			//we will only have one results as email is a primary key. Set maxResults to be 1.
			$maxResults = 1;
			break;
		}
		case customerSearchType::NAME :
		{
			
			if(!isset($maxResults))
			{
				$query = "SELECT * FROM proj_customer WHERE ";
				$query .="CONCAT(firstname, ' ', lastname) LIKE '%$fullname%'";		
				$db_obj->query($query);
				
				$maxResults = $db_obj->affected_rows;
			}
			
			$fullname = $db_obj->real_escape_string($_GET['search']);
			$query = "SELECT * FROM proj_customer WHERE ";
			$query .="CONCAT(firstname, ' ', lastname) LIKE '%$fullname%'";
			$query .= ' LIMIT ' . ( ($_GET['page'] - 1) * $_GET['results'] ) . ', ' . $_GET['results'];

			break;
		}
	}

	//actually preform the query, regardles of the type, and see how many rows there are.
	$result_obj = $db_obj->query($query);
	if($result_obj->num_rows != 0)
	{
?>	
		<div class="book_display">
		<h1 class="form-text">Customer Results</h1>
		<table align="center" cellpadding="5">
<?php	
		while( $row = $result_obj->fetch_assoc() ) 
		{
			echo "<tr>";
			echo '<td>' . $row['firstname'] . '</td> ';
			echo '<td>' . $row['lastname'] . '</td>'; 
			echo '<td>' . $row['address_street'] . '</td>' ;
			echo '<td>' . $row['address_city'] . '</td>';
			echo '<td>' . $row['address_state'] . '</td>';
			echo '<td>' . $row['address_zip'] .'</td>';
			echo '<td>' . $row['phone'] . '</td>';
			echo '<td>' . "<a href=myorders.php?email=". $row['email'] . '&page=1&results=10>View Orders</a></td>';
			echo "</tr>";
		}
		echo "</table>";
		echo "</div>";
		//if we aren't on the first page, then we can go back to the previous page we were on
		echo '</br>';
		echo '<div align="center">';
		if($_GET['page'] != 1)
		{	
			
			$previousPage = sprintf('customersearch_results.php?page=%d&results=%d&search=%s&search_type=%d&search_button=%s', 
			$_GET['page']-1, $_GET['results'], urlencode($_GET['search']), $_GET['search_type'], $_GET['search_button'], $maxResults);
			echo '<a href='.$previousPage.'>Previous Page</a>';
		}
		
		//make sure that we have enough results to go onto the next part
		if( $maxResults > $_GET['page'] * $_GET['results']  )
		{
			$nextPage = sprintf('customersearch_results.php?page=%d&results=%d&search=%s&search_type=%d&search_button=%s&max_results=%s', 
			$_GET['page']+1, $_GET['results'], urlencode($_GET['search']), $_GET['search_type'], $_GET['search_button'], $maxResults);
			echo '  <a href='.$nextPage.'>Next Page</a>';
		}					
		
		echo '<label>  Results Per Page</label>';
		echo selectBox('results', 10 , "resultsPerPage", $_GET['results'], "resultsPerPage");
		echo '</div>';
		echo '</form>';
	}
		
	else
	{
?>
		<p align="center">No Results Found</p>
<?php
	}
?>	
	
	</div>
</body>
</html>