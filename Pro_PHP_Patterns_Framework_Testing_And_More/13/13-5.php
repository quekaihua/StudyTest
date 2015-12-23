<?php
/**
 * 范围异常错误用法
 * Created by PhpStorm.
 * User: Administrator
 * Date: 2015/12/23
 * Time: 9:44
 */
function mathy($x){
    if($x==2){
        throw new RangeException('X cannot be 2');
    }else{
        return (1 / ($x - 2));
    }
}