<?php
/**
 * Created by PhpStorm.
 * User: Administrator
 * Date: 2015/12/1
 * Time: 9:06
 */
spl_autoload_register(null,false);
spl_autoload_extensions('.php,.inc,.class,.interface');
function myLoader1($class){
    $class = strtolower($class);
    if(file_exists('1/'.$class.'.class.php')){
        require_once "1/".$class.".class.php";
    }
}
function myLoader2($class){
    $class = strtolower($class);
    if(file_exists('2/'.$class.".php")){
        require_once "2/".$class.".php";
    }
}

if(false === spl_autoload_functions()){
    if(function_exists('__autoload')){
        spl_autoload_register('__autoload',false);
    }
}
spl_autoload_register('myLoader1',true);
spl_autoload_register('myLoader2',true);

var_dump(spl_autoload_call('SomeClass'));  //试着call这个定义类
var_dump(class_exists('SomeClass',false));
if(class_exists('SomeClass',false)){
    echo 'SomeClass was loaded.';
    $instance = new SomeClass();
}else{
    echo 'SomeClass was not found';
}
