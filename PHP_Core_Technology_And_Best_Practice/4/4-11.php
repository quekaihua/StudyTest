<?php
/**
 * Created by PhpStorm.
 * User: Administrator
 * Date: 2015/12/28
 * Time: 15:16
 */
@header('Content-type:text/html;charset:utf-8');

$ch = curl_init();
curl_setopt($ch,CURLOPT_URL,"http://3g.qq.com");
curl_setopt($ch,CURLOPT_RETURNTRANSFER,1);
$h = array('HTTP_VIA : HTTP/1.1 SNXA-PS-WAP-GW21(infoX-WISG,Huawei Technologies)',
           'HTTP_ACCEPT : application/vnd.wmlscriptc,text/vnd.wap,wml,application/vnd.wap.html+xml.application/xhtml+xml,text/html,multipart/mixed,*/*',
           'HTTP_ACCEPT_CHARSET : ISO-8859-1,US-ASCII,UTF-8;Q=0.8,ISO-8859-15;Q=0.8,ISO-10646-UCS-2;UTF-16;Q=0.6');
curl_setopt($ch,CURLOPT_HTTPHEADER,$h);
curl_setopt($ch,CURLOPT_HTTP_VERSION,CURL_HTTP_VERSION_1_0);

$output = curl_exec($ch);
curl_close($ch);

$ch = curl_init();
curl_setopt($ch,CURLOPT_URL,"http://info50.3g.qq.com/g/s?aid=index&amp;s_it=3&amp;g_from=3gindex&amp;&amp;g_f=1283");
curl_setopt($ch,CURLOPT_RETURNTRANSFER,1);
curl_setopt($ch,CURLOPT_HTTPHEADER,$h);
curl_setopt($ch,CURLOPT_HTTP_VERSION,CURL_HTTP_VERSION_1_0);

$output = curl_exec($ch);
curl_close($ch);
echo $output;