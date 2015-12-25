<?php
/**
 * Created by PhpStorm.
 * User: Administrator
 * Date: 2015/12/25
 * Time: 10:40
 */
$html = file_get_contents('http://www.baidu.com/');
print_r($http_response_header);
$fp = fopen('http://www.baidu.com/','r');
print_r(stream_get_meta_data($fp));
fclose($fp);