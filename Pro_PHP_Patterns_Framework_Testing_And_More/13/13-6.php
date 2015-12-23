<?php
/**
 * Created by PhpStorm.
 * User: Administrator
 * Date: 2015/12/23
 * Time: 9:44
 */
class Sensor{
    public static function getTemperature(){
        return 51;
    }
}

class Monitor{
    public static function watch(){
        $temp = Sensor::getTemperature();
        if(($temp < -50) || ($temp > 50)){
            throw new RangeException('The sennor broke down');
        }
    }
}

Monitor::watch();