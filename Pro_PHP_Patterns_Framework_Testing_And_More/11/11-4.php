<?php
/**
 * Created by PhpStorm.
 * User: Administrator
 * Date: 2015/12/22
 * Time: 17:15
 */
$pathName = '..';
foreach(new DirectoryIterator($pathName) as $fileInfo){
    echo $fileInfo."\n";
}