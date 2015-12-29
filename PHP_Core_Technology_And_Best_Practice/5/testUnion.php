<?php
/**
 * Created by PhpStorm.
 * User: Administrator
 * Date: 2015/12/29
 * Time: 8:44
 */
$uid = 23;
$member_table = 'member'.$uid%5;
$sql = "select * from {$member_table} union";

$table = array('member0','member1','member2','member3','member4');
foreach($table as $v){
    $sql .= " select * from {$v} union ";
}
    $sql = substr($sql,0,-6);

echo $sql;