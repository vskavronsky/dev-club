<?php
    require_once 'Gun.php';
    
    try {
        $beretta = new Gun();
        
        echo $beretta . PHP_EOL;
        
        $beretta->reload();
        $beretta->prepare();
        
        $count = 5;
        for ( $i = 0; $i < $count; ++$i ) {
            $beretta->shoot();
            echo PHP_EOL;    
        }
        echo $beretta . PHP_EOL;
        
    } catch( InvalidParam $ex ) {
        echo $ex->getMessage() . PHP_EOL;
    } catch ( InvalidAttribute $ex ) {
        echo $ex->getMessage() . PHP_EOL;
    } catch( NotReadyToShoot $ex ) {
        echo $ex->getMessage() . PHP_EOL;
    } catch ( OutOfRounds $ex ) {
        echo $ex->getMessage() . PHP_EOL;
    }
?>
