<?php
class MyObject{
	static function myMethod(){
		static::myOtherMethod();
	}

	static function myOtherMethod(){
		echo "called from MyObject";
	}
}

class MyOtherObject extends MyObject{
	static function myOtherMethod(){
		echo 'called from MyOtherObject';
	}
}

MyOtherObject::myMethod();