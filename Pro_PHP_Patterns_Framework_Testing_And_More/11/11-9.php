<?php
/**
 * Created by PhpStorm.
 * User: Administrator
 * Date: 2015/12/23
 * Time: 13:52
 */
class FileExtensionFinder extends FilterIterator{
    protected $predicate,$path;

    public function __construct($path,$predicate){
        $this->predicate = $predicate;
        $this->path = $path;
        $it = new RecursiveDirectoryIterator($path);
        $flatIterator = new RecursiveDirectoryIterator($it);

        parent::__construct($flatIterator);
    }

    public function accept(){

    }
}