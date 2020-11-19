<?php
    $a = fgets(STDIN);
    $b = fgets(STDIN);
    $c = fgets(STDIN);
    $d = fgets(STDIN);
    
    $max = $a;
    if ( $b > $max ) {
        $max = $b;
    }
    if ( $c > $max ) {
        $max = $c;
    }
    if ( $d > $max ) {
        $max = $d;
    }
    
    echo $max . PHP_EOL;
?>
