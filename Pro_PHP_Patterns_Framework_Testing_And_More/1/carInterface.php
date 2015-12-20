<?php
interface ISpeedInfo{
	function getMaximumSpeed();
}

class Car{}

class FastCar extends Car implements ISpeedInfo{
	function getMaximumSpeed(){
		return 150;
	}
}

class Street{
	protected $speedLimit;
	protected $cars;

	public function __construct($speedLimit = 200){
		$this->cars = array();
		$this->speedLimit = $speedLimit;
	}

	function isStreetLegal($car){
		if($car instanceof ISpeedInfo){
			if($car->getMaximumSpeed() < $this->speedLimit){
				return true;
			}else{
				return false;
			}
		}else{
			return false;
		}
	}

	public function addCar($car){
		if($this->isStreetLegal($car)){
			echo 'The Car was allowed on the road.';
			$this->cars[] = $car;
		}else{
			echo 'The Car is too fast and was not allowed on the road.';
		}
	}
}