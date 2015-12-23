<?php
/**
 * Created by PhpStorm.
 * User: Administrator
 * Date: 2015/12/23
 * Time: 9:44
 */
function printmax10($str){
    if(strlen($str) > 10){
        throw new LengthException("Input was too long");
    }
    echo $str;
}

printmax10('asdfgh');
printmax10('asdfghjkljk');