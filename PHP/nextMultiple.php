<?php
    $dividend = fgets(STDIN);
    $divisor = fgets(STDIN);
    $nextMultiple;
    
    if ( $divisor < 0 ) {
        $divisor *= -1;
    }
    $nextMultiple = $dividend - $dividend % $divisor;
    
    if ( $nextMultiple < $dividend ) {
        $nextMultiple += $divisor;
    }
    echo $nextMultiple . PHP_EOL;
?>
