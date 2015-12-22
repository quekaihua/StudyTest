<?php
/**
 * Created by PhpStorm.
 * User: Administrator
 * Date: 2015/12/22
 * Time: 16:15
 */
//安全调用自动加载
if(false === spl_autoload_functions()){
    if(function_exists('__autoload')){
        spl_autoload_register('__autoload',false);
    }
}