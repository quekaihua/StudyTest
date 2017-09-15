<?php

class Crypt_HMAC{
    
    function __construct($key, $method = 'md5'){
        if(!in_array($method, array('sha1', 'md5'))){
            die("Unsupported hash function '$method'.");
        }
        $this->_func = $method;

        if($strlen($key) > 64){
            $key = pack('H32', $method($key))
        }
    }
}