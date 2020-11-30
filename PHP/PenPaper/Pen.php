<?php
    require_once 'Paper.php';
    require_once 'Exceptions/OutOfInk.php';

    class Pen {
        private $inkAmount, $inkCapacity;
        
        private function validate($value) {
            if ( is_int($value) && $value > 0 ) {
                return $value;
            }
            throw new InvalidParam("Invalid param '$value'.");
        }
        
        public function __construct($inkCapacity = 4096) {
            $this->inkAmount = $this->validate($inkCapacity);
            $this->inkCapacity = $inkCapacity;
        }
        
        public function __get($name) {
            if ( property_exists($this, $name) ) {
                return $this->$name;
            }
            throw new InvalidAttribute("Attribute error: attribute '$name' not found.");
        }
        
        public function write(Paper $paper, $msg) {
            if ( $this->inkAmount == 0 ) {
                throw new OutOfInk("Please, refill your pen!");
            }
            if ( strlen($msg) > $this->inkAmount ) {
                $paper->addContent(substr($msg, 0, $this->inkAmount));
                $this->inkAmount = 0;
                return;
            }
            $paper->addContent($msg);
            $this->inkAmount -= strlen($msg);
        }
        
        public function refill() {
            $this->inkAmount = $this->inkCapacity;
        }
    }
?>
