<?php
/**
 * Created by PhpStorm.
 * User: Administrator
 * Date: 2015/12/22
 * Time: 16:55
 */
$dsn = 'mysql:dbname=renrengou;host=localhost';
$db = new PDO($dsn,'root','root');
$pdoStatement = $db->query('SELECT * FROM rrg_admin_log');

$iterator = new IteratorIterator($pdoStatement);
$limitIterator = new LimitIterator($iterator,0,10);
$tenRecordArray = iterator_to_array(($limitIterator));
print_r($tenRecordArray);