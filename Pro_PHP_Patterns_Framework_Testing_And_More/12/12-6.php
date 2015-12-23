<?php
/**
 * Created by PhpStorm.
 * User: Administrator
 * Date: 2015/12/23
 * Time: 10:43
 */
require_once 'Product.php';
require_once 'Cart.php';

$cart = new Cart();
$cart[] = new Product('00231-A','A',1.99);
$cart[] = new Product('00231-B','B',1.88);
echo $cart->getCartTotal();