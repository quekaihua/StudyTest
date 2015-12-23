<?php
/**
 * Created by PhpStorm.
 * User: Administrator
 * Date: 2015/12/23
 * Time: 10:13
 */
class MyArray implements ArrayAccess{
    protected $_arr;

    public function __construct(){
        $this->_arr = array();
    }

    public function offsetSet($offset,$value){
        $this->_arr[$offset] = $value;
    }

    public function offsetGet($offset){
        return $this->_arr[$offset];
    }

    public function offsetExists($offset){
        return array_key_exists($offset,$this->_arr);
    }

    public function offsetUnset($offset){
        unset($this->_arr[$offset]);
    }
}

$myArray = new MyArray();
$myArray['first'] = 'test';
$demo = $myArray['first'];
echo $demo."\n";
unset($myArray['first']);
$demo = $myArray['first'];
echo $demo."\n";
