<?php
include "4-2.php";

error_reporting(0);

function connectToDatabase(){
	if(!$conn = mysql_connect('localhost','root','root1')){
		throw new DatabaseException("Frinedly Message");
	}
}

try{
	connectToDatabase();
}catch(DatabaseException $e){
	echo $e->getMessage()."</br>";
	echo $e->getDatabaseErrorMessage();
}