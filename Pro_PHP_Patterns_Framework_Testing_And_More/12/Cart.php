<?php
/**
 * Created by PhpStorm.
 * User: Administrator
 * Date: 2015/12/23
 * Time: 10:43
 */
require_once('Product.php');

class Cart extends ArrayObject{
    protected $_products;

    public function __construct(){
        $this->_products = array();
        parent::__construct($this->_products);
    }

    public function getCartTotal(){
        for($i=$sum=0,$cnt = count($this);
            $i<$cnt;
            $sum+=$this[$i++]->getPrice());

        return $sum;
    }
}

/*$cart = new Cart();
$product = new Product('00231-A','Description',1.99);
$cart[] = $product;
print_r($cart);*/