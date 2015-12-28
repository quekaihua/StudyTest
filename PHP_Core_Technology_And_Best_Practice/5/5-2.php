<?php
/**
 * Created by PhpStorm.
 * User: Administrator
 * Date: 2015/12/28
 * Time: 16:15
 */
$id = 10;
$dsn = "mysql: host=localhost;dbname=test";
$dbh = new PDO($dsn,'root','root');

$sth = $dbh->prepare('SELECT * FROM test WHERE id > :id ');
$sth->bindParam(':id',$id,PDO::PARAM_INT);
$sth->execute();
$result = $sth->fetchAll(PDO::FETCH_ASSOC);
print_r($result);

