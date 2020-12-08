<?php
    require_once 'Passport.php';

    function exceptionAutoload($className) {
        $path = "Exceptions/$className.php";
        include($path);
    }
    spl_autoload_register("exceptionAutoload");

    class CheckFunctions {
        const MAX_NUMBER = 999999;
        const MIN_NUMBER = 100000;
        const SERIES_LENGTH = 2;
        
        public static function isString($value) {
            if ( is_string($value) ) {
                return $value;
            }
            throw new InvalidParam("Invalid param '$value'.");
        }
        
        public static function isNumeric($value) {
            if ( is_numeric($value) && $value > 0 ) {
                return $value;
            }
            throw new InvalidParam("Invalid param '$value'.");
        }
        
        public static function validate($value) {
            $date_arr = explode('/', $value);
            
            if ( count($date_arr) == 3 ) {
                if ( checkdate($date_arr[0], $date_arr[1], $date_arr[2]) ) {
                    return $value;
                }
                throw new InvalidParam("Invalid param '$value'.");
            }
            throw new InvalidParam("Invalid param '$value'.");
        }
        
        public static function verify($passportSeries, $passportNumber) {
            self::isString($passportSeries);
            self::isNumeric($passportNumber);
            
            if ( strlen($passportSeries) > self::SERIES_LENGTH ) {
                throw new SeriesLengthExceeded("Series length should be only two uppercase characters!");
            }
            
            if ( strcasecmp($passportSeries, Passport::getPassportSeries() ) <= 0 ) {
                throw new InvalidNewSeries("Make sure that new passport serie is bigger than existing one!");
            }
            
            if ( $passportNumber > self::MAX_NUMBER || $passportNumber < self::MIN_NUMBER ) {
                throw new InvalidPassportNumber("The passport number should be from 100000 till 999999!");
            }
        }
    }
?>
