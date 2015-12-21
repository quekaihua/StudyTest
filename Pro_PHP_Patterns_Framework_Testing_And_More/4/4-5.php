<?php
/**
 * Created by PhpStorm.
 * User: Administrator
 * Date: 2015/12/21
 * Time: 10:07
 */
function exceptionLogger($exception){
    $file = 'exceptionLog.log';
    file_put_contents($file,$exception->__toString(),FILE_APPEND);
}

//set_exception_handler('exceptionLogger');

try{
    $s = 4/1;
    throw new Exception('除数不能为0');
}catch (Exception $e){
    exceptionLogger($e);
}