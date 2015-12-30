<?php
/**
 * Created by PhpStorm.
 * User: Administrator
 * Date: 2015/12/29
 * Time: 13:57
 */
function readParams($sourceFile){
    $prams = array();

    $str = file_get_contents($sourceFile);
    $data = explode("|",$str);
    foreach ($data as $val){
        if($val){
            $p = explode(':',$val);
            $prams[$p[0]] = $p[1];
        }
    }
    return $prams;
}

function writeParams($params,$sourceFile){
    $str = '';
    foreach($params as $key=>$value){
        $str .= $key.":".$value."|";
    }
    file_put_contents($sourceFile,$str);
}

$file = 'param.txt';
$array['key1'] = 'val1';
$array['key2'] = 'val2';
$array['key3'] = 'val3';
writeParams($array,$file);
$output = readParams($file);
print_r($output);