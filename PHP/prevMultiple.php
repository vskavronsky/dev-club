<?php
    $dividend = fgets(STDIN);
    $divisor = fgets(STDIN);
    $prevMultiple;
    
    if ( $divisor < 0 ) {
        $divisor *= -1;
    }
    $prevMultiple = $dividend - $dividend % $divisor;
    
    if ( $prevMultiple > $dividend ) {
        $prevMultiple -= $divisor;
    }
    echo $prevMultiple . PHP_EOL;
?>
