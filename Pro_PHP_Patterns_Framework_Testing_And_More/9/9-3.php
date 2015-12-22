<?php
/**
 * Created by PhpStorm.
 * User: Administrator
 * Date: 2015/12/22
 * Time: 12:07
 */
interface ArrayAccess{
    public function offsetExists($offset);
    public function offsetset($offset,$value);
    public function offsetGet($offset);
    public function offsetUnset($offset);
}