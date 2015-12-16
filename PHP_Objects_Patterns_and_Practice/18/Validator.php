<?php
/**
 * Created by PhpStorm.
 * User: Administrator
 * Date: 2015/12/16
 * Time: 16:14
 */
include 'UserStore.php';

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

$store = new UserStore();
$store->addUser("bob williiams","bob@example.com","12345");
$validator = new Validator($store);
if($validator->validdateUser("bob@example.com","1235")){
    print "pass,friend!\n";
}else{
    print_r($store->getUser("bob@example.com"));
}