<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8" />
<link rel="stylesheet" type="text/css" href="styles.css" />
<title>That's Bargain! Books</title>
</head>

<body>

<?php

	require_once("mysqli.php");
	global $db_obj;
	//print the header information
	$orderID = $db_obj->real_escape_string($_GET["orderID"]);
	$query = "SELECT * FROM proj_orders NATURAL JOIN proj_customer WHERE order_ID = '$orderID'";
	$result_obj = $db_obj->query($query);
	
	//if the order is in the database, print out the recipt. Else, display an error
	if($result_obj->num_rows != 0)
	{	
		$row = $result_obj->fetch_assoc();
		$validResult = isset($row);
?>
		<table cellpadding="5" class="recipt_table">
<?php
    	if($validResult)
		{	
			echo "<tr><td>That's Bargain! Books</td></tr>";
			echo "<tr><td>1-800-444-1111</td></tr>";
			echo "<tr><td> Order #: " . $row['order_ID'] . "</td></tr>";
			echo "<tr><td>-----------------------------------------------------------------------------</td></tr>";
			echo "<tr><td>".$row['firstname'] . " " . $row['lastname'] . "</td></tr>";
			echo "<tr><td>". $row['address_street'] . "</td></tr>";
			echo "<tr><td>".$row['address_city'] . ", " . $row['address_state'] . " ". $row['address_zip'] . "</td></tr>";
			echo "<tr><td>".$row['order_date'] . "</td></tr>";
			echo "<tr><td>----------------------------------------------------------------------------</td></tr>";
		}
?>	
		</table>	
	
    
	<table cellpadding="10">
<?php   
    	//print information about the books bought
		if($validResult) 
		{
			$query = "SELECT ISBN, title, qty, amt FROM proj_book NATURAL JOIN proj_order_items WHERE order_ID = '$orderID'";
			$result_obj = $db_obj->query($query);
			$headerPrinted = false;
			$subtotal = 0.0;
			while( ($row = $result_obj->fetch_assoc()) )
			{
				if(!$headerPrinted)
				{
					echo "<tr>";
					echo "<td>" . "ISBN" . "</td>";	
					echo "<td>" . "Title" . "</td>";
					echo "<td>" . "Qty". "</td>";
					echo "<td>" . "Amt" . "</td>";
					echo "</tr>";
					$headerPrinted = true;
				}
	
				echo "<tr>";
				echo "<td>" . $row['ISBN'] . "</td>";
				echo "<td>" . $row['title'] . "</td>";
				echo "<td>" . $row['qty'] . "</td>";
				echo "<td>" . $row['amt'] . "</td></tr>";
				$subtotal += $row['amt'];
			}
		}
?>
	</table>

	<table cellpadding="10">
<?php
		if($validResult)
		{
			echo "<tr><td>----------------------------------------------------------------------------</td></tr>";
			echo "<tr><td>Subtotal: $". $subtotal ."</tr></td>";
			echo "<tr><td>Shipping: $4.99</tr></td>";
			echo "<tr><td>Sales Tax: $". number_format($subtotal*(.10),2) . "</tr></td>";
			echo "<tr><td>Total: $". number_format($subtotal + $subtotal*(.10) + 4.99,2) . "</tr></td>";
		}

	}
	//else, error out
	else
	{
		echo '<p align=center>Order Not Found</p>';
	}

?>
</body>
</html>