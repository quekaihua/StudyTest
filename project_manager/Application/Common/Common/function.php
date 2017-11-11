<?php

function apiSuccess($msg, $code = 1000){
    $arr['code'] = $code;
    $arr['msg'] = $msg;
    return $arr;
}

function apiFail($msg, $code = 1001){
    $arr['code'] = $code;
    $arr['msg'] = $msg;
    return $arr;
}

function copy_dir($src,$dst) {
    $dir = opendir($src);
    mkdir($dst);
    while(false !== ( $file = readdir($dir)) ) {
      if (( $file != '.' ) && ( $file != '..' )) {
        if ( is_dir($src . '/' . $file) ) {
          copy_dir($src . '/' . $file,$dst . '/' . $file);
          continue;
        }
        else {
          copy($src . '/' . $file,$dst . '/' . $file);
        }
      }
    }
    closedir($dir);
}