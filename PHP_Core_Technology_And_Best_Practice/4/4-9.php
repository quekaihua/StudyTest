<?php
/**
 * Created by PhpStorm.
 * User: Administrator
 * Date: 2015/12/28
 * Time: 11:22
 */
$ch = curl_init();

curl_setopt($ch,CURLOPT_URL,"http://www.php.net");
curl_setopt($ch,CURLOPT_RETURNTRANSFER,1);
curl_setopt($ch,CURLOPT_HEADER,1);
curl_setopt($ch,CURLOPT_HTTP_VERSION,CURL_HTTP_VERSION_1_0);

$output = curl_exec($ch);

$info = curl_getinfo($ch);
//echo '获取'.$info['url'].'耗时'.$info['total_time'].'秒';

print_r($info);

curl_close($ch);
