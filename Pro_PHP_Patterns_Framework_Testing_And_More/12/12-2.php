<?php
/**
 * Created by PhpStorm.
 * User: Administrator
 * Date: 2015/12/23
 * Time: 10:42
 */
$myArray = new ArrayObject();
$myArray['first'] = 'test';
$myArray['second'] = 'value2';
foreach($myArray as $key=>$value){
    echo $key.'='.$value."\n";
}
$demo = $myArray['first'];
unset($myArray['first']);
$numElements = count($myArray);
echo $numElements."\n";
foreach($myArray as $key=>$value){
    echo $key.'='.$value."\n";
}