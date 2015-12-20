<?php
class MyObject{

}

class MyFactory{

	public static function factory(){
		return new MyObject();
	}
}

$instance = MyFactory::factory();