<?php
/**
 * Created by PhpStorm.
 * User: Administrator
 * Date: 2015/12/22
 * Time: 16:15
 */
spl_autoload_register(null,false);
spl_autoload_extensions('.php,.inc,.class,.interface');
function myLoader1($class){
    require_once($class.'.inc');
}

function myLoader2($class){

}

spl_autoload_register('myLoader1',false);
spl_autoload_register('myLoader2',false);
$test = new SomeClass();