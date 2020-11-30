<?php
    function myAutoload($className) {
        $path = "Exceptions/" . $className . ".php";
        include($path);
    }
    spl_autoload_register("myAutoload");
    
    class Gun {
        const SHOT = 1;
        const BULLET = 1;
        
        private $model;
        private $totalShots;
        private $isReady;
        private $amount, $capacity;
        
        private function isString($value) {
            if ( is_string($value) ) {
                return $value;
            }
            throw new InvalidParam("Invalid param '$value'.");
        }
        
        private function isNumber($value) {
            if ( is_int($value) ) {
                return $value;
            }
            throw new InvalidParam("Invalid param '$value'.");
        }
        
        public function __construct($model = "Beretta", $capacity = 8) {
            $this->model = $this->isString($model);
            $this->capacity = $this->isNumber($capacity);
            $this->amount = 0;
            $this->totalShots = 0;
            $this->isReady = false; 
        }
        
        public function __get($name) {
            if ( property_exists($this, $name) ) {
                return $this->$name;
            }
            throw new InvalidAttribute("Attribute error: attribute '$name' not found.");
        }
        
        public function prepare() {
            $this->isReady = !$this->isReady;
        }
        
        public function reload() {
            if ( $this->capacity <= 0 ) {
                echo "You entered incorrect magazine capacity!";
                return;
            }
            $this->amount = $this->capacity;
        }
        
        public function shoot() {
            if ( !$this->isReady ) {
                throw new NotReadyToShoot("Please, prepare your gun for shooting!");
            }
            if ( $this->amount == 0 ) {
                throw new OutOfRounds("Please, reload your gun to continue shooting!");
            }
            echo "Bang!";
            $this->amount -= self::BULLET;
            $this->totalShots += self::SHOT;
        }
        
        public function __toString() {
            $convertedIsReady = $this->isReady ? 'true' : 'false';
            
            return "Characteristics of the gun:" . PHP_EOL 
                . "The gun model - " . $this->model . "." . PHP_EOL
                . "Ready to shoot - " . $convertedIsReady . "." . PHP_EOL
                . "Bullets quantity - " . $this->amount . "." . PHP_EOL
                . "Magazine capacity - " . $this->capacity . "." . PHP_EOL
                . "Total shots - " . $this->totalShots . ".";
        }
    }
?>
