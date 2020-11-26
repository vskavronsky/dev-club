<?php
    require_once 'Point.php';
    
    try {
        $a = new Point(2, 5);
        $b = new Point(3, 7);
        $c = new Point(3, 7);
        $d = $a;
        $e = clone $a;

        echo "a: " . $a . PHP_EOL;
        echo "b: " . $b . PHP_EOL;
        echo "c: " . $c . PHP_EOL;
        
        $e->x = 42;
        $e->y = 36;
        echo "e.x: " . $e->x . PHP_EOL;
        echo "e.y: " . $e->y . PHP_EOL;

        $a->compare($b);
        $b->compare($c);

        $a->isTheSameInstance($b);
        $a->isTheSameInstance($d);

        echo "The distance between a and b is - " . $a->distance($b) . PHP_EOL;
        echo "The distance between b and c is - " . $b->distance($c) . PHP_EOL;
        
    } catch( InvalidParam $ex ) {
        echo $ex->getMessage() . PHP_EOL;
    } catch ( InvalidAttribute $ex ) {
        echo $ex->getMessage() . PHP_EOL;
    }
?>
