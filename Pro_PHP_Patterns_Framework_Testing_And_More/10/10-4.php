<?php
/**
 * Created by PhpStorm.
 * User: Administrator
 * Date: 2015/12/22
 * Time: 16:55
 */
$arrFirst = new ArrayIterator(array(1,2,3));
$arrSecond = new ArrayIterator(array(4,5,6));

$iterator = new AppendIterator();
$iterator->append($arrSecond);
$iterator->append($arrFirst);

foreach($iterator as $number){
    echo $number;
}