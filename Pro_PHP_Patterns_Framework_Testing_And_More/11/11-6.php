<?php
/**
 * Created by PhpStorm.
 * User: Administrator
 * Date: 2015/12/23
 * Time: 13:52
 */
$pathName = "..";
$iterator = new RecursiveDirectoryIterator($pathName);
$treeIterator = new RecursiveTreeIterator($iterator);

foreach($treeIterator as $entry){
    if($entry != '.' || $entry != '..'){
        echo $entry."\n";
    }
}