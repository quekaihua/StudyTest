<?php
/**
 * Created by PhpStorm.
 * User: Administrator
 * Date: 2015/12/25
 * Time: 10:52
 */


$data = "ie=utf-8&kw=%E9%97%AE%E9%81%93&fid=450313&tid=4231976539&vcode_md5=&floor_num=94&rich_text=1&tbs=fcf31a7ee0f8af1a1451014604&content=%E5%A5%BD%E6%B0%B4&files=%5B%5D&mouse_pwd=102%2C101%2C97%2C121%2C100%2C101%2C98%2C99%2C99%2C92%2C100%2C121%2C101%2C121%2C100%2C121%2C101%2C121%2C100%2C121%2C101%2C121%2C100%2C121%2C101%2C121%2C100%2C121%2C101%2C92%2C103%2C109%2C102%2C100%2C97%2C92%2C100%2C99%2C101%2C101%2C121%2C108%2C101%2C101%2C14510145737850&mouse_pwd_t=1451014573785&mouse_pwd_isclick=0&__type__=reply";
$header = "Content-type: application/x-www-form-urlencoded; charset=UTF-8"."\r\n".
          "Content-Length: ".strlen($data)."\r\n".
          "Cookie: BAIDUID=A92B4E60FBFBFF68CF12EBC9592F4751:FG=1; BIDUPSID=A92B4E60FBFBFF68CF12EBC9592F4751; PSTM=1439262957; TIEBA_USERTYPE=3b1b6fd78ddafaa34b971eff; bdshare_firstime=1439347642570; BDUSS=Z5Skg0eWdJNkZhT3NPaUFvc2ZZYThsNmxCRlNGSHQxQU1nZE42SzdOVDRrdkpWQVFBQUFBJCQAAAAAAAAAAAEAAAAm85gh0rm7sLDNyP0AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAPgFy1X4BctVOV; TIEBAUID=5a13ed66a1f3d467a3da11ea; MCITY=-%3A; H_PS_PSSID=18286_1460_18534_12825_18501_18546_18559_17001_17073_15159_11490_18554_10632; showCardBeforeSign=1; rpln_guide=1; wise_device=0; LONGID=563671846"."\r\n".
          "User-Agent: Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/46.0.2490.86 Safari/537.36"."\r\n".
          "Referer: http://tieba.baidu.com/p/4231976539"."\r\n";

$opts = array(
    'http'  =>  array(
        'method'    =>  "POST",
        'header'    =>  $header,
        'content'   =>  $data
    )
);
$context = stream_context_create($opts);
$html = @file_get_contents('http://tieba.baidu.com/p/4231976539?pn=3',false,$context);
