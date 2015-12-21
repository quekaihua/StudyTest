<?php
/**
 * Created by PhpStorm.
 * User: Administrator
 * Date: 2015/12/21
 * Time: 16:42
 */
function ComputeMenu(){
    $menu = array();
    foreach(findPlugins() as $plugin){
        if($plugin->hasMethod('getMenuItems')){
            $reflectionMethod = $plugin->getMethod('getMenuItems');
            if($reflectionMethod->isStatic()){
                $items = $reflectionMethod->invoke(null);
            }else{
                $pluginInstance = $plugin->newInstance();
                $items = $reflectionMethod->invoke($pluginInstance);
            }
            $menu = array_merge($menu,$items);
        }
    }
    return $menu;
}