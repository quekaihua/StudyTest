<?php
/**
 * Created by PhpStorm.
 * User: Administrator
 * Date: 2015/12/22
 * Time: 12:01
 */
function print_entry($iterator){
    print($iterator->current());
    return true;
}

$array = array(1,2,3);
$iterator = new ArrayIterator($array);
iterator_apply($iterator,'print_entry',array($iterator));