<?php
    require_once '_Countable.php';
    require_once 'Exceptions/InvalidParam.php';
    require_once 'Exceptions/InvalidAttribute.php';
    
    class Journal extends _Countable {
        private $title;
        private $price;
        
        private function isString($value) {
            if ( is_string($value) ) {
                return $value;
            }
            throw new InvalidParam("Invalid param '{$value}'.");
        }
        
        private function isNumeric($value) {
            if ( is_numeric($value) && $value > 0 ) {
                return $value;
            }
            throw new InvalidParam("Invalid param '{$value}'.");
        }
        
        public function __construct($title, $price) {
            $this->title = $this->isString($title);
            $this->price = $this->isNumeric($price);
            parent::__construct();
        }
        
        public function __get($name) {
            if ( property_exists($this, $name) ) {
                return $this->$name;    
            }
            throw new InvalidAttribute("Attribute error: attribute '{$name}' not found.");
        }
        
        public function __set($name, $value) {
            switch($name) {
                case "title":
                    $this->title = $this->isString($value);
                    break;
                case "price":
                    $this->price = $this->isNumeric($value);
                    break;
                default:
                    throw new InvalidAttribute("Attribute error: attribute '{$name}' not found.");
            }
        }
        
        public function __clone() {
            parent::__construct();
        }
        
        public function __toString() {
            return "{$this->title}: {$this->price}$";
        }
    }
?>
