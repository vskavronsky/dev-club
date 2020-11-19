<?php
    $a = fgets(STDIN);
    $b = fgets(STDIN);
    $c = fgets(STDIN);
    
    $max = $a;
    if ( $b > $max ) {
        $max = $b;
    }
    if ( $c > $max ) {
        $max = $c;
    }
    
    echo $max . PHP_EOL;
?>
