<?php 
class Playlist{
	private $__songs;
	
	public function __construct(){
		$this->__songs = array();
	}
	
	public function addSong($location,$title){
		$song = array('location'=>$location,'title'=>$title);
		$this->__songs[] = $song;
	}
	
	public function getM3U(){
		$m3u = '#EXTM3U\n\n';
		
		foreach($this->__songs as $song){
			$m3u .= "#EXTINF:-1,".$song['title']."\n";
			$m3u .= $song['location']."\n";
		}
		
		return $m3u;
	}
	
	public function getPLS(){
		$pls = "[playlist]\nNumberEntries=".count($this->__songs)."\n\n";
		foreach($this->__songs as $songCount => $song){
			$counter = $songCount + 1;
			$pls .= "File{$counter}={$song['location']}\n";
			$pls .= "Title{$counter}={$song['title']}\n";
			$pls .= "Length{$counter}=-1\n\n";
		}
		return $pls;
	}
}

class newPlaylist{
	private $__songs;
	private $__typeObject;
	
	public function __construct(){
		$this->__songs = array();
		$oject = "{$type}Playlist";
		$this->__typeObject = new $object;
	}
	
	public function addSong($location,$title){
		$song = array('location'=>$location,'title'=>$title);
		$this->songs[] = $song;
	}
	
	public function getPlaylist(){
		$playlist = $this->__typeObject->getPlaylist($this->__songs);
		return $playlist;
	}
}