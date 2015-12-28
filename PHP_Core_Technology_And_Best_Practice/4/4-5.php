<?php
/**
 * Created by PhpStorm.
 * User: Administrator
 * Date: 2015/12/28
 * Time: 10:00
 */
$sock = fsockopen('192.168.0.2',8001,$errno,$errstr,1);
if(!$sock){
    echo "$errstr($errno)<br/> \n";
}else{
    socket_set_blocking($sock,false);
    fwrite($sock,"send data...\r\n");
    fwrite($sock,"end \r\n");

    while(!feof($sock)){
        echo fread($sock,128);
        flush();
        do_flush();
        sleep(1);
    }
    fclose($sock);
}