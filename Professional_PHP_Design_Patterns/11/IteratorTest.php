<?php 
	include 'Book.php';
	include 'BookList.php';
	include 'BookListIterator.php';
	include 'BookListReverseIterator';
	
	class IteratorTest extends PHPUnit_Framework_TestCase{
		protected $bookList;
		
		protected function setUp(){
			$this->bookList = new BookList();
			$this->bookList->addBook(new Book('Leaning PHP Design Patterns','William Sanders'));
			$this->bookList->addBook(new Book('Professional PHP Design Patterns','Aaron Saray'));
			$this->bookList->addBook(new Book('Clean Code','Robert C.Martin'));
		}
		
		public function expectedAuthors(){
			return array(
				array(
					array(
						'Leaning PHP Design Patterns by William Sanders',
						'Professional PHP Design Patterns by Aaron Saray',
						'Clean Code by Robert C.Martin'
					)
				),
			);
		}
		
		public function testUseAIteratorAndValidateAuthors($expected){
			$iterator = new BookListIterator($this->bookList);
			while($iterator->valid()){
				$expectedBook = array_shift($expected);
				$this->assertEquals($expectedBook,$iterator->current()->getAuthorAndTitle());
				$iterator->next();
			}
		}
		
		public function testUseAReverseIteratorAndValiddateAuthors($expected){
			$iterator = new BookListReverseIterator($this->bookList);
			
			while($iterator->valid()){
				$expectedBook = array_pop($expected);
				$this->assertEquals($expectedBook,$iterator->current()->getAuthorAndTitle());
				$iterator->next();
			}
		}
		
		public function testBookRemove(){
			$this->bookList->removeBook($this->bookList->getBook(0));
			$this->assertEquals($this->bookList->count(),2);
		}
	}