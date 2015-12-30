<?php
/**
 * Created by PhpStorm.
 * User: Administrator
 * Date: 2015/12/30
 * Time: 14:37
 */
abstract class Employee{
    protected $name;
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

class NastyBoss{
    private $employees = array();

    function addEmployee($employeeName){
        $this->employees[] = new Minion($employeeName);
    }

    function projectFails(){
        if(count($this->employees) > 0){
            $emp = array_pop($this->employees);
            $emp->fire();
        }
    }
}

$boss = new NastyBoss();
$boss->addEmployee("barry");
$boss->addEmployee("bob");
$boss->addEmployee("mary");
$boss->projectFails();
$boss->projectFails();
