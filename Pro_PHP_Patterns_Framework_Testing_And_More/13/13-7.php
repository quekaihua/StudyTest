<?php
/**
 * Created by PhpStorm.
 * User: Administrator
 * Date: 2015/12/23
 * Time: 9:44
 */
function sum($a,$b){
    if(!is_numeric($a) || !is_numeric($b)){
        throw new InvalidArgumentException("Invalid Argument");
    }
    return ($a + $b);
}
echo sum(1,2);
echo sum('a','b');