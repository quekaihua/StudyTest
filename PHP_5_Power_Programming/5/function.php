<?php

function create_parameters($array)
{
    $data = '';
    $ret = [];

    foreach($array as $key => $value){
        $data .= $key . $value;
        $ret[] = "$key=$value";
    }

    $hash = md5($data);
    $ret[]="hash=$hash";

    return join('&', $ret);
}

echo 'script.php?' . create_parameters(['cause' => 'vars']);
