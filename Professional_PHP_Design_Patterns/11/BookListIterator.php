<?php 
class BookListIterator implements Iterator{
	private $booklist;
	protected $currentBook = 0;
	
	public function __construct(BookList $booklist){
		$this->booklist = $booklist;
	}
	
	public function current(){
		return $this->booklist->getBook($this->currentBook);
	}
	
	public function next(){
		$this->currentBook++;
	}
	
	public function key(){
		return $this->currentBook;
	}
	
	public function valid(){
		return null !== $this->booklist->getBook($this->currentBook);
	}
	
	public function rewind(){
		$this->currentBook = 0;
	}
}