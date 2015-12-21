<?php
/**
 * Created by PhpStorm.
 * User: Administrator
 * Date: 2015/12/21
 * Time: 10:07
 */
class DatabaseException extends Exception{
    const ConnectionFailed = 1;
    const LoginFailed = 2;
    const PermissionDenied = 3;

    public function __construct($code = 0){
        switch($code){
            case DatabaseException::ConnectionFailed:
                $message = 'Database connection failed';
                break;
            case DatabaseException::LoginFailed:
                $message = 'Login to the database was rejected';
                break;
            case DatabaseException::PermissionDenied:
                $message = 'Permission denied';
                break;
            default:
                $message = 'Unknow Error';
        }

        parent::__construct($message,$code);
    }
}

error_reporting(0);

try{
    if(!$conn = mysql_connect('localhost','root','123')){
        throw new DatabaseException(DatabaseException::ConnectionFailed);
    }
}catch (DatabaseException $e){
    echo $e->getMessage();
}