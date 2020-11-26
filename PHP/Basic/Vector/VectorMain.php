<?php
    require_once 'Vector.php';
    
    try {
        $a = new Vector();
        $b = new Vector(8, 27);
        
        echo "a: " . $a . PHP_EOL;
        echo "b: " . $b . PHP_EOL;
        
        $a->x = 6;
        $a->y = 15;
        
        echo "New a.x: " . $a->x . ", New a.y: " . $a->y . PHP_EOL;
        
        $a->compare($b);
        
        echo "Length of the a - " . $a->len() . PHP_EOL;
        
        $a->increment($b);
        $b->decrement($a);
        $sum = $a->add($b);
        $diff = $b->subtract($a);
        
        echo "Incremented a: " . $a . PHP_EOL;
        echo "Decremented b: " . $b . PHP_EOL;
        echo "Sum of the a and b - " . $sum . PHP_EOL;
        echo "Difference of the b and a - " . $diff . PHP_EOL;
        
    } catch( InvalidParam $ex ) {
        echo $ex->getMessage() . PHP_EOL;
    } catch ( InvalidAttribute $ex ) {
        echo $ex->getMessage() . PHP_EOL;
    }
?>
