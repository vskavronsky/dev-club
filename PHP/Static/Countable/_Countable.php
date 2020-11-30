<?php
    class _Countable {
        private static $totalCount = 0;
        
        public function __construct() {
            self::$totalCount += 1;
        }
        
        public function __destruct() {
            self::$totalCount -= 1;    
        }
        
        public static function count() {
            return "Total items: " . self::$totalCount . PHP_EOL;
        }
    }
?>
