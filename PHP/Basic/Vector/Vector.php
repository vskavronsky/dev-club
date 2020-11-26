<?php
    function myAutoload($className) {
        $path = "Exceptions/" . $className . ".php";
        include($path);
    }
    spl_autoload_register("myAutoload");
    
    class Vector {
        private $x, $y; 
        
        private function validate($value) {
            if ( is_numeric($value) ) {
                return $value;
            }
            throw new InvalidParam("Invalid param '$value'.");
        }
        
        public function __construct($x = 0.0, $y = 0.0) {
            $this->x = $this->validate($x);
            $this->y = $this->validate($y);
        }
        
        public function __get($name) {
            if ( property_exists($this, $name) ) {
                return $this->$name;
            }
            throw new InvalidAttribute("Attribute error: attribute '$name' not found.");
        }
        
        public function __set($name, $value) {
            if ( property_exists($this, $name) ) {
                $this->$name = $this->validate($value);
            } else {
                throw new InvalidAttribute("Attribute error: attribute '$name' not found.");
            }
        }
        
        public function len() {
            return hypot($this->x, $this->y);
        }
        
        public function compare(Vector $other) {
            if ( $this == $other ) {
                echo $this . " is equeal to " . $other . PHP_EOL;
            } else {
                echo $this . " is not equeal to " . $other . PHP_EOL;
            }
        }
        
        public function increment(Vector $other) {
            $this->x += $other->x;
            $this->y += $other->y;
        }
        
        public function decrement(Vector $other) {
            $this->x -= $other->x;
            $this->y -= $other->y;
        }
        
        public function add(Vector $other) {
            return new Vector($this->x + $other->x, $this->y + $other->y);
        }
        
        public function subtract(Vector $other) {
            return new Vector($this->x - $other->x, $this->y - $other->y);
        }
        
        public function __toString() {
            return "($this->x, $this->y)";
        }
    }
?>
