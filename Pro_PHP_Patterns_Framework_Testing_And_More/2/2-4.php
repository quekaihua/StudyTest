<?php
class MyObject{
	function myMethod(){
		echo "Standard Functionality\n";
	}
}

class MyOtherObject extends MyObject{
	function myMethod(){
		echo "New Functionality";
		parent::myMethod();
	}
}

$obj = new MyOtherObject();
$obj->myMethod();