<?php
class userClass{
	public function userMethod($userParam='default'){}
}

foreach(get_declared_classes() as $class){
	$reflectionClass = new ReflectionClass($class);
	if($reflectionClass->isUserDefined()){
		Reflection::export($reflectionClass);
	}
}