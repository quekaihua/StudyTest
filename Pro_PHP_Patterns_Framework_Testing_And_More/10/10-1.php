<?php
/**
 * Created by PhpStorm.
 * User: Administrator
 * Date: 2015/12/22
 * Time: 16:46
 */
class MyIterableClass implements IteratorAggregate{
    protected $arr;

    public function __construct(){
        $this->arr = array(1,2,3);
    }

    public function getIterator(){
        return new ArrayIterator($this->arr);
    }
}

foreach(new MyIterableClass() as $value){
    echo $value."\n";
}