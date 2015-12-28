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

if($output !== FALSE){
    echo $output;
}else{
    echo "cURL Error: ".curl_error($ch);
}

curl_close($ch);
