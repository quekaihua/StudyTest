<?php
/**
 * Created by PhpStorm.
 * User: Administrator
 * Date: 2015/12/1
 * Time: 11:29
 */
$it = new SimpleXMLIterator(file_get_contents('test.xml'));

foreach($it as $key=>$node){
    echo $key."<br/>";
    if($it->hasChildren()){
        foreach($it->getChildren() as $element=>$value){
            echo "\t".$element." : ".$value."<br/>";
        }
    }
}