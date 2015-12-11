<?php
/**
 * Created by PhpStorm.
 * User: Administrator
 * Date: 2015/12/11
 * Time: 14:36
 */
class lib{
    const SETTING_AN_ARRAY = TRUE;

    const NO_PERSISTENT_STORAGE = FALSE;

    public static function getitem($name,$persist = TRUE){
        $return = NULL;
        if(isset($_SESSION[$name])){
            $return = $_SESSION[$name];
            if(!$persist) unset($_SESSION[$name]);
        }

        return $return;
    }

    public static function setitem($name,$value,$array = false){
        if($array){
            if(!isset($_SESSION[$name])){
                $_SESSION[$name] = array();
                $_SESSION[$name][] = $value;
            }
        }else{
            $_SESSION[$name] = $value;
        }
    }
}