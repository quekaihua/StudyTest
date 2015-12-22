<?php
/**
 * Created by PhpStorm.
 * User: Administrator
 * Date: 2015/12/22
 * Time: 11:50
 */
interface Iterator{
    public function current();
    public function key();
    public function next();
    public function rewind();
    public function valid();
}