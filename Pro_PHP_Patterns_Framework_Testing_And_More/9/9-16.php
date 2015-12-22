<?php
/**
 * Created by PhpStorm.
 * User: Administrator
 * Date: 2015/12/22
 * Time: 16:15
 */
class a{}
$instance = new a();
echo spl_object_hash($instance);