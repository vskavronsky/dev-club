<?php
    require_once 'Point.php';
    require_once 'Exceptions/OutOfFuel.php';
    require_once 'Exceptions/ToMuchFuel.php';
    
    class Car {
        private $model;
        private $location;
        private $fuelConsumption;
        private $fuelAmount, $fuelCapacity;
        
        private function isNumber($value) {
            if ( is_numeric($value) && $value > 0 ) {
                return $value;
            }
            throw new InvalidParam("Invalid param '$value'.");
        }
        
        private function isPoint($value) {
            if ( $value instanceof Point ) {
                return $value;
            }
            throw new InvalidParam("Invalid param '$value'.");
        }
        
        private function isString($value) {
            if ( is_string($value) ) {
                return $value;
            }
            throw new InvalidParam("Invalid param '$value'.");
        }
        
        private function validate($value) {
            if ( is_numeric($value) ) {
                return $value;
            }
            throw new InvalidParam("Invalid param '$value'.");
        }
        
        public function __construct($capacity = 60, $consumption = 0.6, $location = null, $model = 'Mercedes') {
            $this->fuelCapacity = $this->isNumber($capacity);
            $this->fuelConsumption = $this->isNumber($consumption);
            $this->location = is_null($location) ? new Point(0, 0) : $this->isPoint($location);
            $this->model = $this->isString($model);
            $this->fuelAmount = 0;
        }
        
        public function __get($name) {
            if ( property_exists($this, $name) ) {
                return $this->$name;
            }
            throw new InvalidAttribute("Attribute error: attribute '$name' not found.");
        }
        
        public function drive(Point $destination) {
            $neededFuel = $this->location->distance($destination) * $this->fuelConsumption;
    
            if ( $this->fuelAmount == 0 ) {
                throw new OutOfFuel("Your fuel tank is empty! Needed fuel for travel is $neededFuel liters.");
            }
            if ( $this->fuelAmount < $neededFuel ) {
                echo "Can't move! Needed fuel for travel is $neededFuel liters.";
                return;
            }
        
            $this->fuelAmount -= $neededFuel;
            $this->fuelCapacity -= $this->fuelAmount;
            $this->location = $destination;
        }

        public function travel($x, $y) {
            $this->validate($x);
            $this->validate($y);
            $this->drive(new Point($x, $y));
        }

        public function refill($fuel) {
            $this->isNumber($fuel);
                        
            if ( $this->fuelAmount + $fuel > $this->fuelCapacity ) {
                $this->fuelAmount = $this->fuelCapacity;
                throw new ToMuchFuel("To much fuel! Your fuel tank is full.");
            }   
            $this->fuelAmount += $fuel;
        }
    
        public function __toString() {
            return "Characteristics of the car:" . PHP_EOL
                . "Car model - $this->model." . PHP_EOL
                . "Car location - $this->location." . PHP_EOL
                . "Fuel amount - $this->fuelAmount liters." . PHP_EOL
                . "Tank capacity - $this->fuelCapacity liters." . PHP_EOL
                . "Fuel consumption - $this->fuelConsumption liters.";
        }
    }
?>
