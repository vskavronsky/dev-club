<?php
    require_once 'Exceptions/InvalidParam.php';
    require_once 'Exceptions/InvalidAttribute.php';
    require_once 'Exceptions/OutOfSpace.php';
    
    class Paper {
        private $symbols, $maxSymbols;
        private $content;
        
        private function validate($value) {
            if ( is_int($value) && $value > 0 ) {
                return $value;
            }
            throw new InvalidParam("Invalid param '$value'.");
        }
        
        public function __construct($maxSymbols = 4096) {
            $this->maxSymbols = $this->validate($maxSymbols);
            $this->symbols = 0;
            $this->content = "";
        }
        
        public function __get($name) {
            if ( property_exists($this, $name) ) {
                return $this->$name;
            }
            throw new InvalidAttribute("Attribute error: attribute '$name' not found.");
        }
        
        public function addContent($msg) {
            $this->symbols = strlen($this->content) + strlen($msg);
            
            if ( strlen($this->content) == $this->maxSymbols ) {
                throw new OutOfSpace("Not enough space! You've used all free space on the paper!");
            }
            if ( $this->symbols > $this->maxSymbols ) {
                $this->content .= substr($msg, 0, $this->maxSymbols - strlen($this->content));
                return;
            }
            $this->content .= $msg;
        }
        
        public function show() {
            echo $this->content . PHP_EOL;
        }
    }
?>
