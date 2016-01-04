<?php
/**
 * Created by PhpStorm.
 * User: Administrator
 * Date: 2015/12/31
 * Time: 9:33
 */
//使用pear包
//echo get_include_path();die;
require_once("Config.php");

class MyConfig{
    private $rootObj;

    function __construct($filename,$type='xml'){
        $this->type = $type;
        $conf = new Config();
        if(! is_null($filename)){
            $this->rootObj = $conf->_parse_config_section($type);
        }else{
            $this->rootObj = new Config_Container('section','config');
            $conf->setroot($this->rootObj);
        }
    }

    function set($secname,$key,$val){
        $section = $this->getOrCreate($this->rootObj,$secname);
        $directive = $this->getOrCreate($section,$key,$val);
        $directive->setContent($val);
    }

    private function getOrCreate(Config_Container $cont,$name,$value = null){
        $itemtype = is_null($value) ? 'section' :'directive';
        if($child = $cont->searchPath(array($name))){
            return $child;
        }
        return $cont->createItem($itemtype,$name,null);
    }

    function __toString(){
        return $this->rootObj->toString($this->type);
    }
}

/*$myconf = new MyConfig();
$myconf->set("directies","prefs","/tmp/myapp/prefs");
$myconf->set("directies","scratch","/tmp/");
$myconf->set("general","version","1.0");
echo $myconf;*/