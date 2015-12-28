<?php
/**
 * Created by PhpStorm.
 * User: Administrator
 * Date: 2015/12/28
 * Time: 17:00
 */

$dsn = "mysql: host=localhost;dbname=test";
$db = new PDO($dsn,'root','root');

$db->beginTransaction();
$db->exec("INSERT INTO test(first_name,last_name) VALUES ('shabi','shabi')");
$db->exec("INSERT INTO test(first_name,last_name) VALUES ('shabi','shabi','shabi')");
$db->commit();