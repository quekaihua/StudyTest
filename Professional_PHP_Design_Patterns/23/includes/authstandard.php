<?php
/**
 * Created by PhpStorm.
 * User: Administrator
 * Date: 2015/12/15
 * Time: 11:41
 */
class authstandard implements authenticatorinterface{
    public function authenticate(user $user,$password){
        if($user->password == lib::makehashedpassword($user,$password)){
            return true;
        }else{
            return false;
        }
    }
}