<?php
/**
 * Created by PhpStorm.
 * User: Administrator
 * Date: 2015/12/15
 * Time: 11:39
 */
interface authenticatorinterface{
    public function authenticate(user $user, $password);
}