<?php
    require_once 'Exceptions/InvalidParam.php';
    require_once 'Exceptions/InvalidAttribute.php';
    
    class Point {
        private $x, $y; 
        
        protected function validate($value) {
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
        
        public function distance(Point $other) {
            return hypot($other->x-$this->x, $other->y-$this->y);
        }
        
        public function compare(Point $other) {
            if ( $this == $other ) {
                echo $this . " is equeal to " . $other . PHP_EOL;
            } else {
                echo $this . " is not equal to " . $other . PHP_EOL;
            }
        }
        
        public function __toString() {
            return "($this->x, $this->y)";
        }
    }
?>
