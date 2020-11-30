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
        
        echo Journal::count() . PHP_EOL;
        
        $pink->title = 'Playboy';
        $pink->price = 43.77;
        
        echo $pink . PHP_EOL;
        echo $time . PHP_EOL;
        echo $natali . PHP_EOL;
        echo $pink2 . PHP_EOL;
        
        echo Journal::count() . PHP_EOL;
        
        unset($pink2);
        
        echo $pink . PHP_EOL;
        echo $time . PHP_EOL;
        echo $natali . PHP_EOL;
        
        echo Journal::count();
        
    } catch ( InvalidParam $ex ) {
        echo $ex->getMessage() . PHP_EOL;
    } catch ( InvalidAttribute $ex ) {
        echo $ex->getMessage() . PHP_EOL;
    } 
?>
