<?php
    require_once 'Complex.php';
    
    try {
        $a = new Complex(34.7, 31.8);
        $b = new Complex(12, 17);
        $c = new Complex(23, -28);
      
        echo "a.x: " . $a->real . ", a.y: " . $a->imaginary . PHP_EOL;
        echo "b: " . $b . PHP_EOL;
        echo "c: " . $c . PHP_EOL;
      
        $b->compare($c);
      
        $b->increment($c);
        $c->decrement($b);
        $sum = $b->add($c);
        $diff = $b->subtract($c);
        $product = $b->multiply($c);
        
        echo "Incremented b: " . $b . PHP_EOL;
        echo "Decremented c: " . $c . PHP_EOL;
        echo "Sum of the b and c - " . $sum . PHP_EOL;
        echo "Difference of the b and c - " . $diff . PHP_EOL;
        echo "Product of the b and c - " . $product . PHP_EOL;
        
    } catch( InvalidParam $ex ) {
        echo $ex->getMessage() . PHP_EOL;
    } catch ( InvalidAttribute $ex ) {
        echo $ex->getMessage() . PHP_EOL;
    }
?>
