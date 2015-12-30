<?php
/**
 * Created by PhpStorm.
 * User: Administrator
 * Date: 2015/12/29
 * Time: 14:35
 */
abstract class ParamHandler{
    protected $source;
    protected $params = array();

    function __construct($source){
        $this->source = $source;
    }

    function addParam($key,$val){
        $this->params[$key] = $val;
    }

    function getAllParam(){
        return $this->params;
    }

    static function getInstance($filename){
        if(preg_match("/\.xml/i",$filename)){
            return new XmlParamHandler($filename);
        }
        return new TextParamHandler($filename);
    }

    abstract function write();
    abstract  function read();
}

class XmlParamHandler extends ParamHandler{
    function write(){
        $string = <<<XML
<?xml version='1.0' encoding='utf-8'?>
<article></article>
XML;

        $xml = simplexml_load_string($string);
        foreach($this->params as $key=>$val){
            $xml->addChild($key,$val);
        }
        file_put_contents($this->source,$xml->asXML());
    }

    function read(){
        $sxe = new SimpleXMLElement($this->source,null,true);
        echo $sxe->asXML();
    }
}

$test = ParamHandler::getInstance("params.xml");
$test->addParam("key1","val1");
$test->addParam("key2","val2");
$test->addParam("key3","val3");
$test->write();
$test->read();