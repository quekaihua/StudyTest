<?php
/**
 * Created by PhpStorm.
 * User: Administrator
 * Date: 2015/12/22
 * Time: 17:15
 */
class RecursiveDirectoryIterator
    extends DirectoryIterator
    implements RecursiveIterator{
    const CURRENT_AS_FILEINFO = 0X00000010;
    const KEY_AS_FILEINFO = 0X00000020;
    const NEW_CURRENT_AS_FILEINFO = 0X00000030;

    function __construct($path,$flags=0){}
    function key(){}
    function current(){}
    function hasChildren(){}
    function getChildren(){}
    function getSubPath(){}
    function getSubPathname(){}
}