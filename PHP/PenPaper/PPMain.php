<?php
    require_once 'Pen.php';
    
    try {
        $pen = new Pen(25);
        $paper = new Paper(12);
        
        $pen->write($paper, "Hello ");
        $pen->write($paper, "world!");
        $paper->show();
        
        try {
            $pen->write($paper, " I love PHP!");    
        
        } catch ( OutOfInk $ex ) {
            echo $ex->getMessage() . PHP_EOL;
        } catch ( OutOfSpace $ex ) {
            echo $ex->getMessage() . PHP_EOL;
        } 
        $paper->show();
        
    } catch ( InvalidParam $ex ) {
        echo $ex->getMessage() . PHP_EOL;
    } catch ( InvalidAttribute $ex ) {
        echo $ex->getMessage() . PHP_EOL;
    } catch ( OutOfInk $ex ) {
        echo $ex->getMessage() . PHP_EOL;
    } catch ( OutOfSpace $ex ) {
        echo $ex->getMessage() . PHP_EOL;
    }
?>
