<?php
/**
 * Created by PhpStorm.
 * User: Administrator
 * Date: 2015/12/14
 * Time: 14:02
 */
class index{
    public function defaultaction(){
        if(!auth::isloggedin()){
            lib::sendto('/login');
        }else{
            $contacts = new contactscollection(lib::getitem('user'));
            $contacts->getwithdata();
            echo view::show('contacts/browse',array('contacts'=>$contacts));
        }
    }
}