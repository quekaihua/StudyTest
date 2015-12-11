<?php 
class CD{
	public $band = '';
	public $title = '';
	public $trackList = array();
	
	public function __construct($band,$title){
		$this->bank = $band;
		$this->title = $title;
	}
	
	public function addTrack($track){
		$this->trackList[] = $track;
	}
}

class CDSearchByandIterator implements Iterator{
	private $__CDs = array();
	private $__valid = FALSE;
	
	public function __construct($bandName){
		$db = mysql_connect('localhohst','root','root');
		mysql_select_db('test');
		
		$sql = "select CD.id, CD.band, CD.title, tracks.tracknum, ";
		$sql .= "tracks.title as tracktitle ";
		$sql .= "from CD left join tracks on CD.id = tracks.cid where band = '";
		$sql .= mysql_real_escape_string($bandName);
		$sql .= "' order by tracks.tracknum";
		
		$results = mysql_query($sql);
		
		$cdID = 0;
		$cd = NULL;
		
		while($result = mysql_fetch_array($results)){
			if($result['id'] !== $cdID){
				if(!is_null($cd)){
					$this->__CDs[] = $cd;
				}
				$cdID = $result['id'];
					$cd = new CD($result['band'],$result['title']);
			}
			
			$cd->addTrack($result['tracktitle']);
		}
		
		$this->__CDs[] = $cd;
	}
	
	public function next(){
		$this->__valid = (next($this->__CDs) === FALSE) ? FALSE : TRUE;
	}
	
	public function rewind(){
		$this->__valid = (reset($this->__CDs) === FALSE) ? FALSE : TRUE;
	}
	
	public function valid(){
		return $this->__valid;
	}
	
	public function current(){
		return current($this->__CDS);
	}
	
	public function key(){
		return key($this->__CDs);
	}
}