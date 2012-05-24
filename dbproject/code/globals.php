<?php	
	

	
	class searchType
	{
		const ISBN = 1;
		const AUTHOR = 2;
		const TITLE = 3;
	
	}
	
	
	$path = '/~esoros/dbproject/code/';
	
	//all of the pages that don't need a navigation bar at the top
	$noNavBarArray = array($path,
						   $path.'index',
					  	   $path.'newuser',	
					       $path.'forgotpass');

	//diaplay a book in a row of a table
	//if a select box is not passed in, then the defaut one that has zero selected will be used instead
	function displayBookTable($title, $ISBN, $author, $pages, $year, $price, $qty, $selectBox)
	{
		echo '<tr>';
		echo '<td><img src="img/'.$ISBN.'.jpg" onError="this.src = \'img/unknown.jpg\'" width=100 height=100/></td>';
		echo '<td>'.$title.'</td>';
		echo '<td>'.$author.'</td>';
		echo '<td>'.$pages.' Pages</td>';
		echo '<td>'.$year.'</td>';
		echo '<td>$'.$price.'</td>';
		//if out of stock, don't let them pick the book
		if(is_null($qty) || $qty < 1)
		{
			echo '<td><p>Out Of Stock</p></td>';
		}
		//else, make a checkbox and a selet box that let's the user pick how many books they want to order
		else
		{
			//basically, we are going to send the information about the book in a serialized array through POST.
			//This way, we don't have to query the database everytime we want to add items to the cart. 
			$book = array("title" => $title, "ISBN" => $ISBN, "author" => $author, "pages" => $pages, 
						  "year" => $year,   "price"=> $price );
			
			if(!isset($selectBox))
			{
				$selectBox = selectBox($ISBN, $qty);
			}
			
			echo '<td><input type="checkbox" name="Books[]" value="'.urlencode(serialize($book)).'"/>'. $selectBox .'</td>';
		}
		echo '</tr>';
	
	}
	
	//returns a string that will make a select button with name = name and all numbers up to a certain number as an option
	//functionCall is an optional parameter. It represents the javascript function that can be called on change
	//selected will have the default value of 1. It is the value that is selected in the select box. 
	function selectBox($name, $maxNum, $functionCall, $selected = 0, $class = NULL)
	{
		
		//set up the opening tag for the select box we are making. 
		$result ='<select';
		
		
		if($name)
		{
			$result .= ' name ="' .$name.'"';
		}
		
		if($functionCall)
		{	
			$result .= ' onchange="'.$functionCall.'();"';
		}
		
		if($class)
		{
			$result .= ' class="' .$class.'"';
		}
		
		$result .= '>';
		
		//add all the options, where selected is the selected value
		for($i = 0; $i <= $maxNum; ++$i)
		{
			if($i == $selected)
			{
				$result .= '<option value='.$i.' selected="selected">'.$i.'</option>';
			}
			else
			{
				$result .= '<option value='.$i.'>'.$i.'</option>';
			}
		}
		
		//close the tag
		$result .= '</select>';
		return $result;
	}
	
	//returns the subtotal of the cart. The cart must be set for this function to work properly
	function subtotal()
	{
		$result = 0;
		reset($_SESSION['cart']);
		foreach($_SESSION['cart'] as $index => $book)
		{
			$result += ($book['price'] * $book['qty']) . '</br>';
		}
		return number_format($result,2);	
	} 
	
	//return the url without the file extension and get information
	function getBaseURL($url)
	{
		$dotPosition = strpos($url , '.');
		$questionMarkPosition = strpos($url,'?');
		if($dotPosition)
		{
			return substr($url, 0, $dotPosition);
		}
		//if there is no '.' in the URL, we need to remove everything before
		//the first question mark to get rid of GET variables in the URL. 
		else if($questionMarkPosition)
		{
			return substr($url, 0, $questionMarkPosition);	
		}
		else
		{
			return $url;
		}
	
	}
	
	//check to see if the email is in the system or not
	//returns the email if it is in the system. 
	//returns false otherwise. 
	function isRegisteredEmail($email)
	{
		global $db_obj;
			
		$query = "SELECT * FROM proj_customer WHERE email = '$email'";
		$result_obj = $db_obj->query($query);
			
		if($result_obj->num_rows == 1)
		{
			$assoc = $result_obj->fetch_assoc();
			return $assoc['email'];
		}
		else
		{
			return FALSE;
		}
	}
	
	//updates a users password in the system. 
	//returns true on sucessful update, false otherwise
	function changePassword($email, $pass)
	{
		global $db_obj;
			
		$pass = md5($pass);
		$query = "UPDATE proj_login SET password_hash = '$pass' WHERE email = '$email'";
		
		if( ($result_obj = $db_obj->query($query)) )
		{
			return TRUE;	
		}
		else
		{
			return FALSE;
		}
	}
	
	//redirects a user to the home page if they are not an administrator
	function redirectNotAdmin()
	{
		session_start();
		if(!isset($_SESSION['admin']))
		{
			header('location:userhome');
			exit();
		}
	}
	
?>