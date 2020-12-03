<?php
    class Identifiable {
        protected $uniqueId;
        private static $id = 0;
        
        public function __construct() {
            self::$id += 1;
            $this->uniqueId = self::$id;
        }
        
        public function getUniqueId() {
            return $this->uniqueId;
        }
    }
?>
