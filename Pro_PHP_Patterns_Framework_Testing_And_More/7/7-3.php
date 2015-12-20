<?php
interface IPlugin{
	public static function getName();
}

function findPlugins(){
	$plugins = array();
	foreach(get_declared_classes() as $class){
		$reflectionClass = new ReflectionClass($class);
		if($reflectionClass->implementsInterface('IPlugin')){
			$plugins[] = $reflectionClass;
		}
	}
	return $plugins;
}

function ComputeMenu(){
	$menu = array();
	foreach(findPlugins() as $plugin){
		if($plugin->hasMethod('getMenuItems')){
			$reflectionMethod = $plugin->getMethod('getMenuItems');
			if($reflectionMethod->isStatic()){
				$items = $reflectionMethod->invoke(null);
			}else{
				$pluginInstance = $plugin->newInstance();
				$items = $reflectionMethod->invoke($pluginInstance);
			}
			$menu = array_merge($menu,$items);
		}
	}
	return $menu;
}