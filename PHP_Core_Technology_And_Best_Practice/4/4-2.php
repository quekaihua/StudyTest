<?php
/**
 * Created by PhpStorm.
 * User: Administrator
 * Date: 2015/12/25
 * Time: 10:52
 */
$data = array('author'=>'白菜大侠','mail'=>'info#aiyooyoo.com','text'=>'博主很给力。');

$data = http_build_query($data);
$opts = array(
    'http'  =>  array(
    'method'    =>  "POST",
    'header'    =>  "Content-type: application/x-www-form-urlencoded\r\n".
        "Content-Length: ".strlen($data)."\r\n",
    'content'   =>  $data
    )
);
$context = stream_context_create($opts);
$html = @file_get_contents('http: //aiyooyoo.com/index.php/archives/7/comment ',false,$context);