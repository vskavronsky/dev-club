<?php
    require_once 'CheckFunctions.php';
    
    function exAutoload($className) {
        $path = "Exceptions/$className.php";
        include($path);
    }
    spl_autoload_register("exAutoload");

    define('MAX_NUMBER', 999999);
    define('MIN_NUMBER', 100000);
    define('SERIES_LENGTH', 2);
    define('MAX_SERIES_LETTER', 'Z');
    define('MIN_SERIES_LETTER', 'A');
    
    class Passport {
        private $series, $number;
        private $firstName, $secondName;
        private $birthDate;
        
        private static $passportSeries = 'AA';
        private static $passportNumber = 100000;
        private static $totalPassports = 0;
        private static $passports = array();
        
        private static function counter() {
            $alphabet = array('A','B','C','D','E','F','G','H','I','J','K','L','M',
                'N','O','P','Q','R','S','T','U','V','W','X','Y','Z');
            
            if ( self::$passportNumber < MAX_NUMBER ) {
                self::$passportNumber += 1;
            } else {
                self::$passportNumber = MIN_NUMBER;
                
                if ( self::$passportSeries[1] < MAX_SERIES_LETTER ) {
                    self::$passportSeries[1] = next($alphabet);
                } else {
                    self::$passportSeries[1] = MIN_SERIES_LETTER;
                    
                    if ( self::$passportSeries[0] < MAX_SERIES_LETTER ) {
                        self::$passportSeries[0] = next($alphabet);
                    } else {
                        throw new ReachedLimit("No free variations of the passport series and numbers!");
                    }
                }
            }
        }
        
        public function __construct($firstName, $secondName, $birthDate) {
            $this->firstName = CheckFunctions::isString($firstName);
            $this->secondName = CheckFunctions::isString($secondName);
            $this->birthDate = CheckFunctions::validate($birthDate);
            
            $this->series = self::$passportSeries;
            $this->number = self::$passportNumber;
            
            self::counter();
            self::$totalPassports += 1;
            self::$passports[] = $this;
        }
        
        public function __get($name) {
            if ( property_exists($this, $name) ) {
                return $this->$name;    
            }
            throw new InvalidAttribute("Attribute error: attribute '{$name}' not found.");
        }
        
        public function __set($name, $value) {
            switch ( $name ) {
                case 'firstName':
                    $this->firstName = CheckFunctions::isString($value);    
                    break;
                case 'secondName':
                    $this->secondName = CheckFunctions::isString($value);
                    break;
                case 'birthDate':
                    $this->birthDate = CheckFunctions::validate($value);
                    break;
                default:
                    throw new InvalidAttribute("Attribute error: attribute '{$name}' not found.");
            }
        }
        
        public static function getPassportSeries() {
            return self::$passportSeries;
        }
        
        public static function getPassportNumber() {
            return self::$passportNumber;
        }
        
        public static function getTotalPassports() {
            return self::$totalPassports;    
        }
        
        public static function setNewSeries($newPassportSeries, $newPassportNumber = MIN_NUMBER) {
            CheckFunctions::verify($newPassportSeries, $newPassportNumber);

            self::$passportSeries = strtoupper($newPassportSeries);
            self::$passportNumber = $newPassportNumber;
        }
        
        public static function findPassport(Passport $passport) {
            $key = array_search($passport, self::$passports);

            if ( $key === false ) {
                throw PassportNotFound("Passport was not found.");
            }
            echo self::$passports[$key] . PHP_EOL;
        }
        
        public static function getAllPassports() {
            foreach ( self::$passports as $value ) {
                echo $value . PHP_EOL;
             }
        }
        
        public function __toString() {
            return "Passport: {$this->series}{$this->number}" . PHP_EOL
                . "--{$this->firstName} {$this->secondName}: {$this->birthDate}.";
        }
    }
?>
