<?php
/**
 * Created by PhpStorm.
 * User: Administrator
 * Date: 2015/12/29
 * Time: 17:30
 */
class CDusesStrage{
    public $title = '';
    public $band = '';

    protected $_strategy;

    public function __construct($title,$band){
        $this->title = $title;
        $this->band = $band;
    }

    public function setStrategyContext($strategyObject){
        $this->_strategy = $strategyObject;
    }

    public function get(){
        return $this->_strategy->get($this);
    }
}

class CDAsXMLStrategy{
    public function get(CDusesStrage $cd){
        $doc = new DomDocument();
        $root = $doc->createElement('CD');
        $root = $doc->appendChild($root);
        $title = $doc->createElement('TITLE',$cd->title);
        $title = $root->appendChild($title);
        $band = $doc->createElement('BAND',$cd->band);
        $band = $root->appendChild($band);

        return $doc->saveXML();
    }
}

class CDAsJSONStrategy{
    public function get(CDusesStrage $cd){
        $json = array();
        $json['CD']['title'] = $cd->title;
        $json['CD']['band'] = $cd->band;

        return json_encode($json);
    }
}

$cd = new CDusesStrage('Never Again','Waste of a Rib');

$cd->setStrategyContext(new CDAsXMLStrategy());
print $cd->get();

$cd->setStrategyContext(new CDAsJSONStrategy());
print $cd->get();
