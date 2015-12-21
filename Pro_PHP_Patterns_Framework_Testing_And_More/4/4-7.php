<?php
/**
 * Created by PhpStorm.
 * User: Administrator
 * Date: 2015/12/21
 * Time: 10:07
 */
class firstException extends Exception{}
class secondException extends Exception{}

try{
    if(3<5) throw new firstException('3<5');
    if(3<5) throw new secondException('3>5');
    if(3<5) throw new firstException('3=5');
}catch (firstException $e){
    echo $e->getMessage();
}catch(secondException $e){
    echo $e->getMessage();
}catch(Exception $e){
    echo $e->getMessage();
}
