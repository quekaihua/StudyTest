<?php
/**
 * Created by PhpStorm.
 * User: Administrator
 * Date: 2015/12/1
 * Time: 11:47
 */
//require_once('path/to/php-src/ext/spl/examples/dbareader.inc');
$it = new DbaReader('test.ini','inifile');
print_r(iterator_to_array($it,true));