<?php
/**
 * Created by PhpStorm.
 * User: Administrator
 * Date: 2015/12/11
 * Time: 17:48
 */
class view{
    public function __construct(){
        ob_start();
    }

    public function finish(){
        $content = ob_get_clean();
        return $content;
    }

    protected static function setviewtype(){
        switch (TRUE){
            case stripos($_SERVER['HTTP_USER_AGENT'],'Windows CE') !== FALSE:
                self::$viewtype = 'mobile';
                break;
            default:
                self::$viewtype = 'default';
        }
    }
}