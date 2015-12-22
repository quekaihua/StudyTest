<?php
/**
 * Created by PhpStorm.
 * User: Administrator
 * Date: 2015/12/22
 * Time: 16:15
 */
if(spl_autoload_call('className') && class_exists('className',false)){
    echo 'className was loaded';
    $instance = new className();
}else{
    echo 'className was not found';
}