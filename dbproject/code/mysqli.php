<?php
// This code connects to a MySQL server dbdev.cs.kent.edu 
//    and sets the database connection object to the global
//    variable $db_obj

    // setting $host
    $host = "dbdev.cs.kent.edu";   // database server host domain name
    // $host = "p:dbdev.cs.kent.edu";   // persistent connection
    // $host = "131.123.35.57";    // or database server host IP address
    $phphost=trim(`hostname`);     // host of php script
    if ( $phphost == $host )
    {  $host="localhost";  }

    $uid="esoros";                  // needs to be secured
    $pass="";
    $dbname="";

    $db_obj = new mysqli($host, $uid, $pass, $dbname);  // connetion object

    if (mysqli_connect_errno())  // connection failed
    {  printf("Can't connect to $host $dbname. %s:%s\n",
         mysqli_connect_errno(), mysqli_connect_error());
       exit();
    }
?>
