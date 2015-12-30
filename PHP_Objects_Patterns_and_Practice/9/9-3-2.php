<?php
/**
 * Created by PhpStorm.
 * User: Administrator
 * Date: 2015/12/30
 * Time: 16:13
 */
abstract class ApptEncoder{
    abstract function encode();
}

class BloggsApptEncoder extends ApptEncoder{
    function encode(){
        return "Appointment data encoded in BloggsCal format\n";
    }
}

class MegaApptEncoder extends ApptEncoder{
    function encode(){
        return "Appointment data encoded in MegaCal format\n";
    }
}

abstract class CommsManager{
    abstract function getHeaderText();
    abstract function getApptEncoder();
    abstract function getTtdEncoder();
    abstract function getContactEncoder();
    abstract function getFooterText();
}

class BloggsCommsManager extends CommsManager{
    function getHeaderText(){
        return "BloggsCal header\n";
    }

    function getApptEncoder(){
        return new BloggsApptEncoder();
    }

    function getTtdEncoder(){
        return new BloggsTtdEncoder();
    }

    function getContactEncoder(){
        return new BloggsContactEncoder();
    }

    function getFooterText(){
        return "BloggsCal footer\n";
    }
}

$comms = new BloggsCommsManager();
$apptEncoder = $comms->getApptEncoder();
print $apptEncoder->encode();