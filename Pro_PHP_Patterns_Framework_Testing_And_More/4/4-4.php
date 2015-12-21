<?php
/**
 * Created by PhpStorm.
 * User: Administrator
 * Date: 2015/12/21
 * Time: 9:54
 */
class LoggedException extends Exception{
    public function __construct(
        $message = null,
        $code = 0,
        $file = 'phpException.log'
    ){
        $this->log($file);
        parent::__construct($message,$code);
    }

    protected function log($file){
        file_put_contents($file,$this->__toString(),FILE_APPEND);
    }
}

include "4-3.php";
