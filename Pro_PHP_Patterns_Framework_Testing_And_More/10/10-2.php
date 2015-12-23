<?php
/**
 * Created by PhpStorm.
 * User: Administrator
 * Date: 2015/12/22
 * Time: 16:54
 */
$arr = array('a','b','c');
$iterator = new ArrayIterator($arr);
foreach($iterator as $val){
    echo $val;
}