<?php
/**
 * Created by PhpStorm.
 * User: Administrator
 * Date: 2015/12/22
 * Time: 14:51
 */
interface Serializable{
    public function serialize();
    public function unserialize($serialized);
}