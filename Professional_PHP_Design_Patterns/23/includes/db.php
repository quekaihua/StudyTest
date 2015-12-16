<?php
/**
 * Created by PhpStorm.
 * User: Administrator
 * Date: 2015/12/15
 * Time: 10:35
 */
abstract class db{
    public static function factory($type){
        return call_user_func($type,'getInstance');
    }

    abstract public function execute($query);
    abstract public function getArray($query);
    abstract public function insertGetID($query);
    abstract public function clean($string);
}