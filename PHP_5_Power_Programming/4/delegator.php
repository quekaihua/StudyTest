<?php
class ClassOne{public function callClassOne(){print "In Class One\n";}}
class ClassTwo{public function callClassTwo(){print "In Class Two\n";}}

class ClassOneDelegator
{
    private $targets;

    function __construct(){
        $this->targets[] = new ClassOne();
    }

    function addObject($obj){
        // $this->targets[] = $obj;
        array_unshift($this->targets, $obj);
    }

    function __call($name, $args){
        foreach($this->targets as $obj){
            // var_dump($this->targets);exit;
            $r = new ReflectionClass($obj);
            if($flag = $r->hasMethod($name)){
                if($method = $r->getMethod($name)){
                    // var_dump($method);exit;
                    if($method->isPublic() && !$method->isAbstract()){
                        return $method->invoke($obj, $args);
                    }
                }
            }
        }
    }
}

$obj = new ClassOneDelegator();
$obj->addObject(new ClassTwo());
$obj->callClassOne();
$obj->callClassTwo();