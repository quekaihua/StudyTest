<?php 
abstract class baseDAO{
	private $__connection;
	
	public function __construct(){
		$this->__connectToDB(DB_USER,DB_PASS,DB_HOST,DB_DATABASE);
	}
	
	private function __connectToDB($user,$pass,$host,$database){
		$this->__connection = mysql_connect($host,$user,$pass);
		mysql_select_db($database,$this->__connection);
	}
	
	public function fetch($value,$key=NULL){
		if(is_null($key)){
			$key = $this->_primaryKey;
		}
		
		$sql = "select * from {$this->_tableName} where {$key}='{$value}'";
		$results = mysql_query($sql,$this->__connection);
		
		$rows = array();
		while($result = mysql_fetch_array($results)){
			$rows[] = $result;
		}
		
		return $rows;
	}
	
	public function update($keyedArray){
		$sql = "update {$this->_tableName} set "; 
		
		$updates = array();
		foreach($keyedArray as $column=>$value){
			$updates[] = "{$column} = '{$value}'";
		}
		
		$sql .= implode(',',$updates);
		$sql .= "where {$this->_primaryKey} = '{$keyedArray[$this->_primaryKey]}'";
		
		mysql_query($sql,$this->__connection);
	}
}

class userDAO extends baseDAO{
	protected $_tableName = 'userTable';
	protected $_primaryKey = 'id';
	
	public function getUserByFirstName($name){
		$result = $this->fetch($name,'firstName');
		return $result;
	}
}

define('DB_USER','root');
define('DB_PASS','root');
define('DB_HOST','localhost');
define('DB_DATABASE','test');

$user = new userDAO();
$userDetailsArray = $user->fetch(1);
print_r($userDetailsArray);

$updates = array('id'=>1,'firstName'=>'aaron');
$user->update($updates);

$allAarons = $user->getUserByFirstName('aaron');
print_r($allAarons);