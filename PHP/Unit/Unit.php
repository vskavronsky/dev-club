<?php
    function myAutoload($className) {
        $path = "Exceptions/$className.php";
        include($path);
    }
    spl_autoload_register('myAutoload');

    class Unit {
        const PART = 2;
        
        private $name;
        private $damage;
        private $hitPoints, $hitPointsLimit;
        
        private function ensureIsAlive() {
            if ( $this->hitPoints == 0 ) {
                throw new UnitIsDead("$this->name is dead.");
            }
        }
        
        private function isString($value) {
            if ( is_string($value) ) {
                return $value;
            }
            throw new InvalidParam("Invalid param '$value'.");
        }
        
        private function isNumber($value) {
            if ( is_numeric($value) && $value > 0 ) {
                return $value;
            }
            throw new InvalidParam("Invalid param '$value'.");
        }
        
        public function __construct($name = 'Carl', $hp = 100, $dmg = 20) {
            $this->name = $this->isString($name);
            $this->hitPoints = $this->isNumber($hp);
            $this->damage = $this->isNumber($dmg);
            $this->hitPointsLimit = $hp;
        }
        
        public function __get($name) {
            if ( property_exists($this, $name) ) {
                return $this->$name;
            }
            throw new InvalidAttribute("Attribute error: attribute '$name' not found.");
        }
        
        public function addHitPoints($hp) {
            $this->ensureIsAlive();
            $this->isNumber($hp);
            
            if ( $this->hitPoints + $hp > $this->hitPointsLimit ) {
                $this->hitPoints = $this->hitPointsLimit;
                return;
            }
            $this->hitPoints += $hp;
        }
        
        public function takeDamage($dmg) {
            $this->ensureIsAlive();
            $this->isNumber($dmg);
            
            if ( $this->hitPoints < $dmg ) {
                $this->hitPoints = 0;
                return;
            }
            $this->hitPoints -= $dmg;
        }
        
        public function attack(Unit $enemy) {
            $this->ensureIsAlive();
            $enemy->takeDamage($this->damage);
            $enemy->counterAttack($this);
        }
        
        public function counterAttack(Unit $enemy) {
            $this->ensureIsAlive();
            $enemy->takeDamage($this->damage / self::PART);
        }
        
        public function __toString() {
            return "$this->name ($this->hitPoints/$this->hitPointsLimit) : $this->damage.";
        }
    }
?>
