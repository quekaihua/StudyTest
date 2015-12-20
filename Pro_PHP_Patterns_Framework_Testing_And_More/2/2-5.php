<?php
class MyObject{
	
	public static $myStaticVar = 0;
	function myMethod(){
		self::$myStaticVar += 2;
		echo self::$myStaticVar."<br/>";
	}
}

class MyOtherObject extends MyObject{

	public static $myStaticVar = 0;
	function myOtherMethod(){
		echo parent::$myStaticVar."<br/>";
		echo self::$myStaticVar."<br/>";
	}
}

$instance1 = new MyObject();
$instance1->myMethod();
$instance2 = new MyObject();
$instance2->myMethod();
$instance3 = new myOtherObject();
$instance3->myOtherMethod();