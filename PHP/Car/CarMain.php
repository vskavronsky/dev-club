<?php
    require_once 'Car.php';
    
    try {
        $car = new Car();
        
        echo $car . PHP_EOL . PHP_EOL;
        
        try {
            $car->refill(100);    
        } catch ( ToMuchFuel $ex ) {
            echo $ex->getMessage() . PHP_EOL . PHP_EOL;
        }
        
        $car->travel(-35, 74);
        echo $car . PHP_EOL . PHP_EOL;
        
    } catch ( InvalidParam $ex ) {
        echo $ex->getMessage() . PHP_EOL;
    } catch ( InvalidAttribute $ex ) {
        echo $ex->getMessage() . PHP_EOL;
    } catch ( OutOfFuel $ex ) {
        echo $ex->getMessage() . PHP_EOL;
    } catch ( ToMuchFuel $ex ) {
        echo $ex->getMessage() . PHP_EOL;
    }
?>
