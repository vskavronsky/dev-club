<?php
    require_once 'Exceptions/InvalidParam.php';
    require_once 'Exceptions/InvalidAttribute.php';

    class Mohican {
        private $name;
        private $age;
        
        private static $mohicanList = array();
        
        private function isNumeric($value) {
            if ( is_numeric($value) && $value > 0 ) {
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
        
        public function __construct($name, $age) {
            $this->name = $this->isString($name);
            $this->age = $this->isNumeric($age);
            self::$mohicanList[] = $this;
        }
        
        public function __get($name) {
            if ( property_exists($this, $name) ) {
                return $this->$name;    
            }
            throw new InvalidAttribute("Attribute error: attribute '{$name}' not found.");
        }
        
        public function __set($name, $value) {
            switch( $name ) {
                case "name":
                    $this->name = $this->isString($value);
                    break;
                case "age":
                    $this->age = $this->isNumeric($value);
                    break;
                default:
                    throw new InvalidAttribute("Attribute error: attribute '{$name}' not found.");
            }
        }
        
        public function erase() {
            $key = array_search($this, self::$mohicanList);
            unset(self::$mohicanList[$key]);
        }
        
        public static function getAll() {
            foreach ( self::$mohicanList as $value ) {
                echo $value . PHP_EOL;
            }
        }
        
        public static function getLast() {
            echo "The last Mohican is - " . end(self::$mohicanList) . PHP_EOL;
        }
        
        public function __clone() {
            self::$mohicanList[] = $this;
        }
        
        public function __toString() {
            return "Name: {$this->name}. Age: {$this->age}.";
        }
    }
?>
