<?php
/**
 * Created by PhpStorm.
 * User: Administrator
 * Date: 2015/12/21
 * Time: 10:07
 */
function demonstration()
{
    try {
        if (1 < 4) throw new Exception('1<4');
    } catch (Exception $e) {
        if ($e->getCode() == 123) {
            echo "success.";
            echo $e->getMessage();
        } else {
            echo "I'm inside.\n";
            throw $e;
        }
    }
}

try{
    demonstration();
}catch (Exception $e){
    echo $e->getMessage();
}
