<?php
/**
 * Created by PhpStorm.
 * User: Administrator
 * Date: 2015/12/28
 * Time: 15:46
 */
try{
    $dsn = "mysql: host=localhost;dbname=test";
    $db = new PDO($dsn,'root','root');

    $db->setAttribute(PDO::ATTR_ERRMODE,PDO::ERRMODE_EXCEPTION);
    $db->exec("SET NAMES 'UTF8'");
    $sql = "INSERT INTO test(first_name,last_name) values('test1','test1')";
    $db->exec($sql);

    $insert = $db->prepare("INSERT INTO test(first_name,last_name) values(?,?)");
    $insert->execute(array('test2','test2'));
    $insert->execute(array('test3','test3'));
//    $insert->execute(array('test4','test4','test4'));

    $sql = "select * from test";
    $query = $db->prepare($sql);
    $query->execute();
    var_dump($query->fetchAll(PDO::FETCH_ASSOC));

}catch (PDOException $err){
    echo $err->getMessage();
}