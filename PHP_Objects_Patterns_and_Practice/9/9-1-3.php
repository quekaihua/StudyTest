<?php
/**
 * Created by PhpStorm.
 * User: Administrator
 * Date: 2015/12/30
 * Time: 14:37
 */
abstract class Employee{
    protected $name;
    private static $types = array('Minion','ClurUp','Wellconnected');

    static function recruit($name){
        $num = rand(1,count(self::$types))-1;
        $class = self::$types[$num];
        return new $class($name);
    }

    function __construct($name){
        $this->name = $name;
    }

    abstract function fire();
}

class Minion extends Employee{
    function fire(){
        print "{$this->name}: I'll clear my desk\n";
    }
}

class ClurUp extends Employee{
    function fire(){
        print "{$this->name}: I'll call my lawyer\n";
    }
}

class WellConnected extends Employee{
    function fire(){
        print "{$this->name}: I'll call my dad\n";
    }
}

class NastyBoss{
    private $employees = array();

    function addEmployee(Employee $employee){
        $this->employees[] = $employee;
    }

    function projectFails(){
        if(count($this->employees) > 0){
            $emp = array_pop($this->employees);
            $emp->fire();
        }
    }
}

$boss = new NastyBoss();
$boss->addEmployee(Employee::recruit("barry"));
$boss->addEmployee(Employee::recruit("bob"));
$boss->addEmployee(Employee::recruit("mary"));
$boss->projectFails();
$boss->projectFails();
$boss->projectFails();
