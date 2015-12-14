<?php
/**
 * Created by PhpStorm.
 * User: Administrator
 * Date: 2015/12/14
 * Time: 14:26
 */
$errors = lib::getitem('error',lib::NO_PERSISTENT_STORAGE);
if(is_array($errors)){
    print '<ul class="error"><li>'.
        implode('</li><li>',$errors).'</li></ul>';
}