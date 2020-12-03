<?php
    require_once 'Journal.php';
    
    try {
        $pink = new Journal('Pink', 6.20);
        $time = new Journal('Time', 11.49);
        $natali = new Journal('Natali', 3.58);
        $pink2 = clone $pink;
        
        echo $pink . PHP_EOL;
        echo $time . PHP_EOL;
        echo $natali . PHP_EOL;
        echo $pink2 . PHP_EOL;
        echo PHP_EOL;
        
        $pink->title = 'Playboy';
        $pink->price = 43.77;
        
        echo $pink . PHP_EOL;
        echo $time . PHP_EOL;
        echo $natali . PHP_EOL;
        echo $pink2 . PHP_EOL;
        echo PHP_EOL; 
        
        unset($time);
        
        echo $pink . PHP_EOL;
        echo $natali . PHP_EOL;
        echo $pink2 . PHP_EOL;
        
    } catch ( InvalidParam $ex ) {
        echo $ex->getMessage() . PHP_EOL;
    } catch ( InvalidAttribute $ex ) {
        echo $ex->getMessage() . PHP_EOL;
    }
?>
