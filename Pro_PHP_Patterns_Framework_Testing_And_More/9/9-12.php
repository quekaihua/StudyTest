<?php
/**
 * Created by PhpStorm.
 * User: Administrator
 * Date: 2015/12/22
 * Time: 16:15
 */
function __autoload($class){
    require_once($class.'.inc');
}

$test = new SomeClass();