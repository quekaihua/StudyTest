<?php
/**
 * Created by PhpStorm.
 * User: Administrator
 * Date: 2015/12/11
 * Time: 14:28
 */
require 'includes/autoloader.php';
require 'includes/exceptions.php';

session_start();

$view = new view();
lib::getitem('controller')->render();
$content = $view->finish();