<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8" />
<link rel="stylesheet" type="text/css" href="styles.css" />
<title>That's Bargain! Books</title>

<script type="text/javascript" src="jquery.js"></script>          
<script type="text/javascript">               

   $(document).ready(function() {
 	 		
 	// $("select").hide();
 	// $(".resultsPerPage").show();
 	 
 	 //$("input").click( function() {
 	 	//alert(this).getElementsByTagName("select");
 	
 	// });
	
 });                     
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
	
	window.location = "search.php" + newURL;
}
                          
</script>	

</head>
<body>
<?php
	 	
	
	require_once("header.php");
	require_once("mysqli.php");
	require_once("globals.php");
	//if max results is not a GET variable, then we have to set it in the search and use it to see if we need to show a link
	//for the next page or not. 
	$maxResults = $_GET['max_results'];
	
	switch($_GET['search_type'])
	{
		case searchType::ISBN:
		{
			$ISBN = $db_obj->real_escape_string($_GET['search']);
			$query = 'SELECT proj_book.ISBN as ISBN, proj_book.TITLE as title, proj_book.price as price, proj_book.num_pages as pages, ';
			$query .= 'proj_book.publish_year as year, CONCAT(proj_author.firstname," ",proj_author.lastname) as author, proj_stock.qty as qty'; 			$query .= ' FROM (proj_book NATURAL JOIN proj_author) LEFT JOIN proj_stock on proj_book.ISBN = proj_stock.ISBN';
			$query .= ' WHERE proj_book.ISBN = "'. $ISBN . '" ';
			//there is only one ISBN, so we don't need a next page and previous page and such
			
			$result_obj = $db_obj->query($query);
			break;
		}
		case searchType::AUTHOR:
		{
			$author = $db_obj->real_escape_string($_GET['search']);
			$names = explode(' ',$author);
			$firstname = $names[0];
			$lastname = $names[1];
			
			//if we don't have the number of results, then we need to find that and send it as a get variable next time
			if(!isset($maxResults))
			{
			
				$query = 'SELECT proj_book.ISBN as ISBN, proj_book.TITLE as title, proj_book.price as price, proj_book.num_pages as pages, ';
				$query .= 'proj_book.publish_year as year, CONCAT(proj_author.firstname," ",proj_author.lastname) as author, proj_stock.qty as 				qty'; 		
				$query .= ' FROM (proj_book NATURAL JOIN proj_author) LEFT JOIN proj_stock on proj_book.ISBN = proj_stock.ISBN';
				$query .= ' WHERE proj_author.firstname LIKE "%'.$firstname.'%" OR proj_author.lastname LIKE "%'.$lastname.'%"';
				$db_obj->query($query);
				
				$maxResults = $db_obj->affected_rows;
				
			}
			
			$query = 'SELECT proj_book.ISBN as ISBN, proj_book.TITLE as title, proj_book.price as price, proj_book.num_pages as pages, ';
			$query .= 'proj_book.publish_year as year, CONCAT(proj_author.firstname," ",proj_author.lastname) as author, proj_stock.qty as 				qty'; 		
			$query .= ' FROM (proj_book NATURAL JOIN proj_author) LEFT JOIN proj_stock on proj_book.ISBN = proj_stock.ISBN';
			$query .= ' WHERE proj_author.firstname LIKE "%'.$firstname.'%" OR proj_author.lastname LIKE "%'.$lastname.'%"';
			$query .= ' LIMIT ' . ( ($_GET['page'] - 1) * $_GET['results'] ) . ', ' . $_GET['results'];
			
			$result_obj = $db_obj->query($query);
			break;
		}
		case searchType::TITLE:
		{
			$title = $db_obj->real_escape_string($_GET['search']);

			//if we don't have the number of results, then we need to find that and send it as a get variable next time
			if(!isset($maxResults))
			{
				$query = 'SELECT proj_book.ISBN as ISBN, proj_book.TITLE as title, proj_book.price as price, proj_book.num_pages as pages, ';
				$query .= 'proj_book.publish_year as year, CONCAT(proj_author.firstname," ",proj_author.lastname) as author, proj_stock.qty as 				qty'; 			
				$query .= ' FROM (proj_book NATURAL JOIN proj_author) LEFT JOIN proj_stock on proj_book.ISBN = proj_stock.ISBN';
				$query .= ' WHERE proj_book.TITLE LIKE "%'.$title.'%" ';								
				$db_obj->query($query);

				$maxResults = $db_obj->affected_rows;
			}
			
			$query = 'SELECT proj_book.ISBN as ISBN, proj_book.TITLE as title, proj_book.price as price, proj_book.num_pages as pages, ';
			$query .= 'proj_book.publish_year as year, CONCAT(proj_author.firstname," ",proj_author.lastname) as author, proj_stock.qty as qty'; 			$query .= ' FROM (proj_book NATURAL JOIN proj_author) LEFT JOIN proj_stock on proj_book.ISBN = proj_stock.ISBN';
			$query .= ' WHERE proj_book.TITLE LIKE "%'.$title.'%" ';
			$query .= ' LIMIT ' . ( ($_GET['page'] - 1) * $_GET['results'] ) . ', ' . $_GET['results'];

			
			$result_obj = $db_obj->query($query);
			break;
		}
		
	}

	if($db_obj->affected_rows > 0)
	{
	//form used to add stuff to the cart
?>
		<form  name="addToCart" action="addtocart.php" method="post">
		<div class="book_display" id="test">
<?php				
				
		//display the books in a table
		echo "<table cellpadding=10 align=center>";
		while( ($row = $result_obj->fetch_assoc())  )
		{	
			//If the qty is a negative number, then it has been "removed" from the system.
			if($row['qty'] >= 0)
			{
				displayBookTable($row['title'],$row['ISBN'],$row['author'],$row['pages'],$row['year'],$row['price'],$row['qty']);
			}
		}
		echo "</table>";
		echo '<p align=center><input type="submit" value="Add To Cart"/></p>';
		echo '</div>';
							
		//results per page and add to cart button
		echo '<div align="center">';
		echo '</br>';
		//if we aren't on the first page, then we can go back to the previous page we were on
		if($_GET['page'] != 1)
		{	
			
			$previousPage = sprintf('search.php?page=%d&results=%d&search=%s&search_type=%d&search_button=%s', 
			$_GET['page']-1, $_GET['results'], urlencode($_GET['search']), $_GET['search_type'], $_GET['search_button'], $maxResults);
			echo '<a href='.$previousPage.'>Previous Page</a>';
		}
		
		//make sure that we have enough results to go onto the next part
		if( $maxResults > $_GET['page'] * $_GET['results']  )
		{
			$nextPage = sprintf('search.php?page=%d&results=%d&search=%s&search_type=%d&search_button=%s&max_results=%s', 
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
		echo '<p align=center>No Results Found</p>';
	}	

?>

</body>
</html>