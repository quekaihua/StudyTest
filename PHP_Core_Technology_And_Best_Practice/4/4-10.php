<?php
/**
 * Created by PhpStorm.
 * User: Administrator
 * Date: 2015/12/28
 * Time: 14:56
 */
//@header('Content-type:image/png');
$url = "http://photo.hanyu.iciba.com/upload/encyclopedia_2/44/ff/bk_44ff0130c18f7aa75b3ab7446761fe7e_A5JWZa.jpg";
$ch = curl_init();

curl_setopt($ch,CURLOPT_URL,$url);
curl_setopt($ch,CURLOPT_RETURNTRANSFER,1);
curl_setopt($ch,CURLOPT_HEADER,0);

$output = curl_exec($ch);

$info = curl_getinfo($ch);
curl_close($ch);

file_put_contents("a.png",$output);
$size = filesize("a.png");
if($size != $info['size_download']){
    echo '下载不完整';
}else{
    echo '下载数据完整';
}