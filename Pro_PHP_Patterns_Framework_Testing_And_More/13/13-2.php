<?php
/**
 * Created by PhpStorm.
 * User: Administrator
 * Date: 2015/12/22
 * Time: 18:38
 */
$logfile = 'log.txt';

try{
    throw new LogicException('Demo');
}catch (LogicException $e){
    $file = new SplFileObject($logfile,'a+');
    $file->fwrite($e->__toString());
}