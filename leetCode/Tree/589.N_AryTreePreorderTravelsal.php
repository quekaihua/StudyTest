<?php
/*
// Definition for a Node.
class Node {
    public $val;
    public $children;

    @param Integer $val 
    @param list<Node> $children 
    function __construct($val, $children) {
        $this->val = $val;
        $this->children = $children;
    }
}
*/

class Node {
    public $val;
	public $children;
	
	/**
	 * Undocumented function
	 * @param Integer $val 
     * @param list<Node> $children 
	 */
    function __construct($val, $children) {
        $this->val = $val;
        $this->children = $children;
    }
}

class Solution {

    /**
     * @param Node $root
     * @return Integer[]
     */
    function preorder($root) {
		$result = [];
		$stack  = [];
		array_push($result, $root->$val);
		array_push($stack);
		while(!empty($stack)) {

		}
    }
}