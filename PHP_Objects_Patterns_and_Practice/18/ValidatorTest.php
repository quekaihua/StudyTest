<?php
/**
 * Created by PhpStorm.
 * User: Administrator
 * Date: 2015/12/17
 * Time: 15:31
 */
require_once ('UserStore.php');
require_once ('Validator.php');

class ValidatorTest extends PHPUnit_Framework_TestCase{
    private $validator;

    public function setUp(){
        $store = new UserStore();
        $store->addUser("bob williams","bob@example.com","12345");
        $this->validator = new Validator($store);
    }

    public function tearDown(){}

    public function testValidate_CorrectPass(){
        $this->assertTrue($this->validator->validdateUser("bob@example.com","12345"),
            "Expecting successful validation");
    }
}