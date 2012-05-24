<?php

	include('/users/cs/ugrad/esoros/public_html/db/mysqli.php');
	include('/users/cs/ugrad/esoros/public_html/db/globals.php');
	include('/users/cs/ugrad/esoros/public_html/db/user_authentication.php');
	
	
	//very basic tests, stuff that you can't see is wrong.
	
	//testing the getBaseUrl function
	assert(getBaseUrl('/esoros/db/test.php') == '/esoros/db/test');
	assert(getBaseUrl('/esoros/db/test.php?test=1') == '/esoros/db/test');
	assert(getBaseUrl('/esoros/db/test?test=1') == '/esoros/db/test');
	assert(getBaseUrl('') == '');
	
	//testing user authentication
	assert(authenticate_user('test@test.com','test') == "USER");
	assert(authenticate_user('testadmin@test.com','testadmin') == 'ADMIN');
	assert(authenticate_user('','') == 0);
	
	//testing for isRegisteredEmail
	assert(isRegisteredEmail('test@test.com') == "test@test.com"  );
	assert(isRegisteredEmail('','') == FALSE);
	

	echo "All Tests Passed!"
	
	
	

?>