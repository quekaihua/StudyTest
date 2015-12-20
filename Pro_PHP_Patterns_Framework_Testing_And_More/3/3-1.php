<?php
class Database{
	private $_db;
	static $_instance;

	private function __construc(){
		$this->_db = pg_connect('dbname=example_db'); //pg数据库连接
	}

	private __clone(){};

	public static function getInstance(){
		if(!(self::$_instance instanceof self)){
			self::$_instance = new self();
		}
		return self::$_instance;
	}

	public function query($sql){
		return pg_query($this->_db,$sql);
	}
}

$db = Database::getInstance();
$db->query('SELECT * FROM example_table');