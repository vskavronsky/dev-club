<?php
    require_once 'Mohican.php';
    
    try {
        $ragnar = new Mohican('Ragnar', 52);
        $lagerta = new Mohican('Lagerta', 45);
        $floki = new Mohican('Floki', 50);
        $harald = new Mohican('Harald', 48);
        $bjorn = clone $ragnar;    
        
        Mohican::getAll();
        Mohican::getLast();
        echo PHP_EOL;
        
        $ragnar->name = 'Oleg';
        $ragnar->age = 43;
        
        Mohican::getAll();
        Mohican::getLast();
        echo PHP_EOL;
        
        $floki->erase();
        $harald->erase();
        
        $ube = new Mohican('Ube', 27);
        
        Mohican::getAll();
        Mohican::getLast();
        
    } catch ( InvalidParam $ex ) {
        echo $ex->getMessage() . PHP_EOL;
    } catch ( InvalidAttribute $ex ) {
        echo $ex->getMessage() . PHP_EOL;
    }
?>
