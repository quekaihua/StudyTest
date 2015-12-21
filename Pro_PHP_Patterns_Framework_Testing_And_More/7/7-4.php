<?php
/**
 * Created by PhpStorm.
 * User: Administrator
 * Date: 2015/12/21
 * Time: 16:40
 */

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