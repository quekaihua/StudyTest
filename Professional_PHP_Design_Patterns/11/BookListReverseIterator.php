<?php 
class BookListReverseIterator implements Iterator{
	private $bookList;
	
	protected $currentBook = 0;
	
	public function __construct(BookList $bookList){
		$this->bookList = $bookList;
		$this->currentBook = $this->bookList->count()-1;
	}
	
	public function current(){
		return $this->bookList->getBook($this->currentBook);
	}
	
	public function next(){
		$this->currentBook--;
	}
	
	public function key(){
		return $this->currentBook;
	}
	
	public function valid(){
		return null !== $this->bookList->getBook($this->currentBook);
	}
	
	public function rewind(){
		$this->currentBook = $this->bookList->count()-1;
	}
}