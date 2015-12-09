<?php 
class CD{
	public $tracks = array();
	public $band = '';
	public $title = '';
	
	public function __construct($title,$band,$tracks){
		$this->title = $title;
		$this->band = $band;
		$this->tracks = $tracks;
	}
}

class CDUpperCase{
	public static function makeString(CD $cd, $type){
		$cd->$type = strtoupper($cd->$type);
	}
	
	public static function makeArray(CD $cd, $type){
		$cd->$type = array_map('strtoupper',$cd->$type);
	}
}

class CDMakeXML{
	public static function create(CD $cd){
		$doc = new DomDocument();
		
		$root = $doc->createElement('CD');
		$root = $doc->appendChild($root);
		
		$title = $doc->createElement('TITLE',$cd->title);
		$title = $root->appendChild($title);
		
		$band = $doc->createElement('BAND',$cd->band);
		$band = $root->appendChild($band);
		
		$tracks = $doc->createElement('TRACKS');
		$tracks = $root->appendChild($tracks);
		
		foreach($cd->tracks as $track){
			$track = $doc->createElement('TRACK',$track);
			$track = $tracks->appendChild($track);
		}
		
		return $doc->saveXML();
	}
}

class WebServiceFacade{
	public static function makeXMLCall(CD $cd){
		CDUpperCase::makeString($cd,'title');
		CDUpperCase::makeString($cd,'band');
		CDUpperCase::makeArray($cd,'tracks');
		
		$xml = CDMakeXML::create($cd);
		
		return $xml;
	}
}
header("Content-type:text/xml");
$cd = new CD('five hundred miles','five jone',array('good-bye','hello','mister kitty'));
print_r(WebServiceFacade::makeXMLCall($cd));