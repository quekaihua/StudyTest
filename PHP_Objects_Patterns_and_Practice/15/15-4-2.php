<?php
/**
 * Created by PhpStorm.
 * User: Administrator
 * Date: 2015/12/31
 * Time: 10:08
 */
//pear包错误处理
include_once 'XML_Feed_Parser.php';
$source = "notthere";
try{
    $myfeed = new XML_Feed_Parser($source);
}catch (XML_Feed_Parser_Exception $e){
    print "message: ".$e->getMessage()."\n";
    print "code: ".$e->getCode()."\n";
    print "error class: ".$e->getErrorClass()."\n";
    print "error method: ".$e->getErrorMethod()."\n";
    print "trace: ".$e->getTraceAsString()."\n";
    print "error data: ";
    print_r($e->getErrorData());
}