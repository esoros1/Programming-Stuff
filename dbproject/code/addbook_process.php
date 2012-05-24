<?php
	
	require_once("mysqli.php");

	$ISBN = $db_obj->real_escape_string($_POST['ISBN']);
	$title = $db_obj->real_escape_string($_POST['title']);
	$price = $db_obj->real_escape_string($_POST['price']);
	$author = $db_obj->real_escape_string($_POST['author']);
	$pages = $db_obj->real_escape_string($_POST['pages']);
	$year = $db_obj->real_escape_string($_POST['year']);
	$stock = $db_obj->real_escape_string($_POST['stock']);
	$author = $db_obj->real_escape_string($_POST['author']);
	$authorNames = explode(' ', $author);
	$authorFirstname = $authorNames[0];
	$authorLastname = $authorNames[1];
		
	
	//validate the image that was uploaded, if one was. It must be a .jpg
	$fileExtension =  pathinfo($_FILES['cover']['name'],PATHINFO_EXTENSION);
	
	
	if($fileExtension != "jpg" &&  $fileExtension != "" )
	{
		header('location:addbook.php?err=-2');
		exit();	
	}
		
	//see if the author is in the author_id table yet. 
	$query = "SELECT author_ID FROM proj_author WHERE firstname = '$authorFirstname' AND lastname = '$authorLastname' ";
	$result_obj = $db_obj->query($query);
	//if there is an author_id, then we can just add the book, otherwise we have to add the author and the book to the DB
	if($result_obj->num_rows == 1)
	{
		$row = $result_obj->fetch_assoc();
		$authorID = $row['author_ID']; 
	}
	//no author_ID, so we just have to add one before we add the book
	else
	{
		$query = "INSERT INTO proj_author VALUES(NULL,'$authorFirstname','$authorLastname')";
		$db_obj->query($query);
		$authorID = $db_obj->insert_id;
		
	}
	//now, we can add the book to the DB
	$query = "INSERT INTO proj_book VALUES('$ISBN', '$title', $authorID, $pages, $year, '$price')";
	$db_obj->query($query);

	//add the album artwork to the img directory
	$target_path = getcwd() . "/img/" . $_POST['ISBN'] . '.' . pathinfo($_FILES['cover']['name'], PATHINFO_EXTENSION);
	//the name of the image for the cover art is just the isbn . file extension
	if ( move_uploaded_file($_FILES['cover']['tmp_name'], $target_path) )
	{
		echo $target_path;
	}
	
	//if it wasn't successful, then the book already exists
	if($db_obj->affected_rows == 1)
	{
		//the update was successful, now add the book to the stock table.
		if(!$stock)
		{
			$query = "INSERT INTO proj_stock VALUES('$ISBN',NULL)";
		}
		else
		{
			$query = "INSERT INTO proj_stock VALUES('$ISBN'," . $stock .")";
	
		}
		$db_obj->query($query);
		header('location:addbook.php?err=1');
		exit();
	}
	else
	{
		header('location:addbook.php?err=-1');
		exit();
	}	
		
	
	
?>