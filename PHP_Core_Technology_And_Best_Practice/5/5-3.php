<?php
/**
 * Created by PhpStorm.
 * User: Administrator
 * Date: 2015/12/28
 * Time: 16:36
 */
function bindParam(&$sql,$location,$var,$type){
    switch($type){
        default:
        case 'STRING':
            $var = addslashes($var);
            $var = "'".$var."'";
            break;
        case 'INTEGER':
        case 'INT':
            $var = (int)$var;
    }

    for($i=1,$pos=0;$i<=$location;$i++){
        $pos = strpos($sql,"? ",$pos+1);
    }

    $sql = substr($sql,0,$pos).$var.substr($sql,$pos+1);
}

$uid = 10086;
$pwd = "pwd";
$sql = "SELECT * FROM table WHERE uid = ? AND pwd = ? ";
bindParam($sql,1,$uid,'INT');
bindParam($sql,1,$pwd,'STRING');
echo $sql;