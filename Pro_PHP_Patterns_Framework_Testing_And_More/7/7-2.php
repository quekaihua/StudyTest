<?php
/**
 * Created by PhpStorm.
 * User: Administrator
 * Date: 2015/12/21
 * Time: 16:40
 */
interface IPlugin{
    function getMenuItems();
    function getArticles();
    function getSideBars();
}

class SomePlugin implements IPlugin{
    public function getMenuItems(){
        return null;
    }

    public function getArticles(){
        return null;
    }

    public function getSideBars(){
        return array('SideBarItem');
    }
}