<?php
/**
 * Created by PhpStorm.
 * User: Administrator
 * Date: 2015/12/23
 * Time: 9:45
 */
function sumThenInsertDemo($a,$b){
    $sum = $a + $b;
    if($sum >= 10){
        throw new OverflowException("$a + $b will overflow storage");
    }

    $link = pg_connect('');
    pg_query($link,'');
}