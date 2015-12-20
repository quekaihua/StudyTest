<?php
	class DatabaseException extends Exception{
		protected $databaseErrorMessage;

		public function __construct($message=null,$code=0){
			$this->databaseErrorMessage = mysql_error();
			parent::__construct($message,$code);
		}

		protected function getDatebaseErrorMessage(){
			return $this->databaseErrorMessage;
		}
	}