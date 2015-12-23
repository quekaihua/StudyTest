<?php
/**
 * Created by PhpStorm.
 * User: Administrator
 * Date: 2015/12/23
 * Time: 9:37
 */
function purchase(){
    if(checkSufficientFunds()){

    }else{
        throw new RuntimeException("The account has insufficient funds.");
    }
}