<?php
    require_once 'Unit.php';
    
    try {
        $carl = new Unit();
        $zombie = new Unit('Zombie', 80, 25);
        
        echo $carl . PHP_EOL . PHP_EOL;
        echo $zombie . PHP_EOL . PHP_EOL;
        
        $carl->attack($zombie);
        
        echo $carl . PHP_EOL . PHP_EOL;
        echo $zombie . PHP_EOL . PHP_EOL;
        
        $zombie->addHitPoints(30);
        
        echo $carl . PHP_EOL . PHP_EOL;
        echo $zombie . PHP_EOL . PHP_EOL;
        
        for ( $i = 4; $i > 0; --$i ) {
            try {
                $carl->attack($zombie);
                
                echo $carl . PHP_EOL . PHP_EOL;
                echo $zombie . PHP_EOL . PHP_EOL;
            } catch( UnitIsDead $ex ) {
                echo $ex->getMessage() . PHP_EOL . PHP_EOL;
            }
        } 
        
        echo $carl . PHP_EOL . PHP_EOL;
        echo $zombie . PHP_EOL . PHP_EOL;
    
    } catch( InvalidParam $ex ) {
        echo $ex->getMessage() . PHP_EOL;
    } catch ( InvalidAttribute $ex ) {
        echo $ex->getMessage() . PHP_EOL;
    } catch( UnitIsDead $ex ) {
        echo $ex->getMessage() . PHP_EOL;
    }
?>
