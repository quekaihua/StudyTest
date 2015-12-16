<?php
/**
 * Created by PhpStorm.
 * User: Administrator
 * Date: 2015/12/16
 * Time: 17:01
 */
require_once('UserStore.php');
require_once('PHPUnit/Framwork/TestCase.php');

class UserStoreTest extends PHPUnit_Framework_TestCase{
    private $store;

    public function setUp(){
        $this->store = new UserStore();
    }

    public function tearDown(){}

    public function testGetUser(){
        $this->store->addUser("bob williams","a@b.com","123456");
        $user = $this->store->getUser("a@b.com");
        $this->assertEquals($user['mail'],"a@b.com");
        $this->assertEquals($user['name'],"bob williams");
        $this->assertEquals($user['pass'],"123456");
    }
}