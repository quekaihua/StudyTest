<?php
interface Observer
{
    function notify(ExchangeRate $obj);
}

class ExchangeRate
{
    static private $instance = null;
    private $observers = [];
    private $exchange_rate;

    private function __construct(){}

    static public function getInstance(){
        if(self::$instance == null){
            self::$instance = new ExchangeRate();
        }
        return self::$instance;
    }

    public function getExchangeRate(){
        return $this->exchange_rate;
    }

    public function setExchangeRate($new_rate){
        $this->exchange_rate = $new_rate;
        $this->notifyObservers();
    }

    public function registerObserver($obj){
        $this->observers[] = $obj;
    }

    function notifyObservers(){
        foreach($this->observers as $obj){
            $obj->notify($this);
        }
    }
}

class ProductItem implements Observer{
    public function __construct(){
        ExchangeRate::getInstance()->registerObserver($this);
    }

    public function notify(ExchangeRate $obj){
        print "Received update!\n";
    }
}

$product1 = new ProductItem();
$product2 = new ProductItem();

ExchangeRate::getInstance()->setExchangeRate(2);