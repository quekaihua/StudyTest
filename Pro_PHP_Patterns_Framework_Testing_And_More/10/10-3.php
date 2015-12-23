<?php
/**
 * Created by PhpStorm.
 * User: Administrator
 * Date: 2015/12/22
 * Time: 16:54
 */
$arr = array(1,2,3,4,5,6,7,8,9);
$arrIterator = new ArrayIterator($arr);
$limitIterator = new LimitIterator($arrIterator,0,9);
foreach($limitIterator as $number){
    echo $number;
}