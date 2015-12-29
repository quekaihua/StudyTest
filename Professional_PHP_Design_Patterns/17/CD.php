<?php

class CD{
    public $title = '';
    public $band = '';

    public function __construct($title,$band){
        $this->title = $title;
        $this->band = $band;
    }

    public function getAsXML(){
        $doc = new DomDocument();
        $root = $doc->createElement('CD');
        $root = $doc->appendChild($root);
        $title = $doc->createElement('TITLE',$this->title);
        $title = $root->appendChild($title);
        $band = $doc->createElement('BAND',$this->band);
        $band = $root->appendChild($band);

        return $doc->saveXML();
    }
}

$cd = new CD('Never Again','Waste of a Rib');
print $cd->getAsXML();
