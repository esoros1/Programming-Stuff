<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8" />
<link rel="stylesheet" type="text/css" href="styles.css" />
<title>Untitled Document</title>
</head>
<body>
<?php
	require_once("header.php");
	require_once("mysqli.php");
	switch($_GET['search_type'])
	{
		case 1:
		{
			$ISBN = $db_obj->real_escape_string($_GET['search']);
			$query = "SELECT * FROM proj_book NATURAL JOIN proj_author WHERE ISBN = '$ISBN'";
			$result_obj = $db_obj->query($query);
			$row = $result_obj->fetch_assoc();
			if ($row)
			{
				echo $row['ISBN'] . " " . $row['TITLE']. " " .$row['firstname'] ." ". $row['lastname'];
			}
			else
			{
				echo '<p align=center>No Results Were Found</p>';
			}
			break;
		}
	}
?>
</body>
</html>