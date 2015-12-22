<?php
/**
 * Created by PhpStorm.
 * User: Administrator
 * Date: 2015/12/22
 * Time: 14:51
 */
error_reporting(E_ALL);

class Base{
    private $baseVar;

    public function __construct(){
        $this->baseVar = 'foo';
    }
}

class Extender extends Base{
    private $extenderVar;

    public function __construct(){
        parent::__construct();
        $this->extenderVar = 'bar';
    }

    public function __sleep(){
        return array('extenderVar','baseVar');
    }
}

$instance = new Extender();
$serialized = serialize($instance);
echo $serialized."\n";
$restored = unserialize($serialized);