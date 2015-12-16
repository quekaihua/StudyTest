<?php
/**
 * Created by PhpStorm.
 * User: Administrator
 * Date: 2015/12/15
 * Time: 11:39
 */
class logout{
    public function defaultaction(){
        lib::setitem('user',NULL);
        lib::sendto();
    }
}