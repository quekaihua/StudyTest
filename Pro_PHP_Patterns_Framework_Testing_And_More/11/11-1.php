<?php
/**
 * Created by PhpStorm.
 * User: Administrator
 * Date: 2015/12/22
 * Time: 17:14
 */
class SplFileInfo{
    function __construct($file_name){}
    function getPath(){}
    function getFilename(){}
//    function getFileInfo(string class_name = null){}
    function getPathname(){}
//    function getPathInfo(string class_name = null){}
    function getPerms(){}
    function getInode(){}
    function getSize(){}
    function getOwner(){}
    function getGroup(){}
    function getATime(){}
    function getMTime(){}
    function getType(){}
    function isWritable(){}
    function isReadable(){}
    function isFile(){}
    function isDir(){}
    function isLink(){}
//    function __toString(){}
    function openFile($mode = 'r', $use_include_path = false,$context = NULL){}
//    function setFileClass(string class_name = "SplFileObject"){}
//    function setInfoClass(string class_name = "SplFileInfo"){}
}