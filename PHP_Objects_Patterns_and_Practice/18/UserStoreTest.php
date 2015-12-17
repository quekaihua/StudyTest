<?php
/**
 * Created by PhpStorm.
 * User: Administrator
 * Date: 2015/12/16
 * Time: 17:01
 */
require_once('UserStore.php');

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

    public function testAddUser_ShortPass(){
        try{
            $this->store->addUser("bob williams","bob@example.com","ffgg");
        }catch (Exception $e){return;}
        $this->fail("Short password exception expected");
    }

    public function testAddUser_ShortPasss(){
        $this->setExpectedException('Exception');
        $this->store->addUser("bob williams","bob@example.com","ffgg");
    }

    public function testAddUser_duplicate(){
        try{
            $ret = $this->store->addUser("bob williams","a@b.com","123456");
            $ret = $this->store->addUser("bob stevens","a@bc.com","123456");
            self::fail("Exception should have been thrown");
        }catch (Exception $e){
            $const = $this->logicalAnd(
                $this->logicalNot($this->contains("bob stevens")),
                $this->isType('array')
            );
            self::AssertThat($this->store->getUser("a@b.com"),$const);
        }
    }
}