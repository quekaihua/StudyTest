<?php
/**
 * Created by PhpStorm.
 * User: Administrator
 * Date: 2015/12/23
 * Time: 13:52
 */
$it = new FindFile('..','11-2.php');
foreach($it as $entry){
    echo $entry."\n";
}