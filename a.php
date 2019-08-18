<?php

$jumbo = "hfdsa";
echo "$jumbo";

$cars = [
	["Volvo", 22, 18],
	["BMW", 15, 13],
	["Saab", 5, 2],
	["Land Rover", 17, 15]
];

for($row = 0; $row < 4; $row++){
	echo "$row";
	for($col = 0; $col < 3; $col++){
		echo "$cars[$row][$col]";
	}
	echo PHP_EOL;
}
