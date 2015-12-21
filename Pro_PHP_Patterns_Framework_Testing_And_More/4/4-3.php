<?php
include "4-2.php";

error_reporting(0);

function connectToDatabase(){
	if(!$conn = mysql_connect('localhost','root','root1')){
//        throw new Exception('hello dberror!!!');
		throw new LoggedException("Frinedly Message");
	}
}

try{
	connectToDatabase();
}catch(DatabaseException $e){
	return;
}