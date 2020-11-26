<?php
    function myAutoload($className) {
        $path = "Exceptions/" . $className . ".php";
        include($path);
    }
    spl_autoload_register("myAutoload");

    class Complex {
        private $real, $imaginary;
        
        private function validate($value) {
            if ( is_numeric($value) ) {
                return $value;
            }
            throw new InvalidParam("Invalid param '$value'.");
        }
        
        public function __construct($real = 0.0, $imaginary = 0.0) {
            $this->real = $this->validate($real);
            $this->imaginary = $this->validate($imaginary);
        }
        
        public function __get($name) {
            if ( property_exists($this, $name) ) {
                return $this->$name;
            }
            throw new InvalidAttribute("Attribute error: attribute '$name' not found.");
        }
        
        public function compare(Complex $other) {
            if ( $this == $other ) {
                echo $this . " is equeal to " . $other . PHP_EOL;
            } else {
                echo $this . " is not equeal to " . $other . PHP_EOL;
            }
        }
        
        public function increment(Complex $other) {
            $this->real += $other->real;
            $this->imaginary += $other->imaginary;
        }
        
        public function decrement(Complex $other) {
            $this->real -= $other->real;
            $this->imaginary -= $other->imaginary;
        }
        
        public function add(Complex $other) {
            return new Complex($this->real + $other->real, $this->imaginary + $other->imaginary);
        }
        
        public function subtract(Complex $other) {
            return new Complex($this->real - $other->real, $this->imaginary - $other->imaginary);
        }
        
        public function multiply(Complex $other) {
            $tempReal = $this->real;
            
            return new Complex($this->real * $other->real - $this->imaginary * $other->imaginary,
                $tempReal * $other->imaginary + $this->imaginary * $other->real);
        }
        
        public function __toString() {
            if ( $this->imaginary < 0 ) {
                return $this->real . $this->imaginary . "i";
            } else {
                return $this->real . "+" . $this->imaginary . "i";
            }
        }
    }
?>
