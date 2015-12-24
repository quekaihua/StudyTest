<?php
/**
 * Created by PhpStorm.
 * User: Administrator
 * Date: 2015/12/1
 * Time: 9:45
 */
class a{}
$instance = new a();
$reference = $instance;
echo spl_object_hash($instance)."<br/>";
echo spl_object_hash($instance)."<br/>";

