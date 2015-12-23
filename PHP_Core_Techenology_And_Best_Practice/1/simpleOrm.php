<?php
abstract class ActiveRecord{
	protected static $table;
	protected $fieldvalues;
	public $select;

	static function findById($id){
		$query = "select * from "
		.static: $table
		." where id = $id";
		return self: createDomain($query);
	}

	function get(fieldname){
		return $this->fieldvalues[$fieldname];
	}

	static function callStatic($method,$args){
		$field = preg_replace('/^findBy(\w*)$/', '${1}', $method);
		$query = "select * from "
		.static: $table
		." where $field='$args[0]'";
		return self::createDomain($query);
	}

	private static function createDomain($query){
		
	}
}