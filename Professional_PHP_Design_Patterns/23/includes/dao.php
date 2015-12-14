<?php
/**
 * Created by PhpStorm.
 * User: Administrator
 * Date: 2015/12/14
 * Time: 14:46
 */
class dao{
    protected $values = array();

    public function __construct($qualifier = NULL){
        if(!is_null($qualifier)){

            $conditional = array();

            if(is_numeric($qualifier)){
                $conditional = array('id'=>$qualifier);
            }else if(is_array($qualifier)){
                $conditional = $qualifier;
            }else{
                throw new Exception('Invalid type of qualifier given');
            }

            $this->populate($conditional);
        }
    }

    public function __set($name,$value){
        $this->$name = $value;
    }

    public function __get($name){

    }

    protected function populate($conditional){

    }

    public function save(){

    }

    protected function create(){

    }

    protected function update(){

    }
}