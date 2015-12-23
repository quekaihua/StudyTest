<?php
/**
 * Created by PhpStorm.
 * User: Administrator
 * Date: 2015/12/23
 * Time: 10:43
 */
class MyObject{}

$a = new MyObject();
$b = array(spl_object_hash($a)=>'Test');
echo $b[spl_object_hash($a)];