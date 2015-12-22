<?php
/**
 * Created by PhpStorm.
 * User: Administrator
 * Date: 2015/12/22
 * Time: 17:14
 */
$fileName = '11-1.php';

$fileInfo = new SplFileInfo($fileName);

$fileProps = array();
$fileProps['path'] = $fileInfo->getPath();
$fileProps['filename'] = $fileInfo->getFilename();