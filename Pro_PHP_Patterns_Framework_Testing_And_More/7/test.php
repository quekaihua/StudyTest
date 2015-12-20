<?php
//Reflection::export(new ReflectionExtension('reflection'));
foreach(get_declared_classes() as $class){
	Reflection::export(new ReflectionClass($class));
}