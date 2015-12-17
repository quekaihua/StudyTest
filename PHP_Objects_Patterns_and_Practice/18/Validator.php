<?php
/**
 * Created by PhpStorm.
 * User: Administrator
 * Date: 2015/12/16
 * Time: 16:14
 */
require_once 'UserStore.php';

class Validator{
    private $store;

    public function __construct(UserStore $store){
        $this->store = $store;
    }

    public function validdateUser($mail,$pass){
        if(!is_array($user = $this->store->getUser($mail))){
            return false;
        }
        if($user['pass'] == $pass){
            return true;
        }
        $this->store->notifyPaswordFailure($mail);
        return false;
    }
}