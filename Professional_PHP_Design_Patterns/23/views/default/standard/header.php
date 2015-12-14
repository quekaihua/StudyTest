<?php
/**
 * Created by PhpStorm.
 * User: Administrator
 * Date: 2015/12/14
 * Time: 13:52
 */
if(auth::isloggedin()){
    $links = array('/'=>'Home',
                   '/contacts/add'=>'Add Contact',
                   '/contacts/import'=>'Import Contacts');
    if(auth::isadmin()){
        $links['/users'] = 'User Admin';
    }
    $links['/logout'] = 'Log Out';

    echo '<ul>';
    foreach($links as $link=>$title){
        echo '<li><a href="'.$link.'">'.$title.'</a></li>';
    }
    echo '</ul>';
}