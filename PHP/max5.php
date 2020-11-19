<?php
    $a = fgets(STDIN);
    $b = fgets(STDIN);
    $c = fgets(STDIN);
    $d = fgets(STDIN);
    $e = fgets(STDIN);
    
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
    if ( $e > $max ) {
        $max = $e;
    }
    
    echo $max . PHP_EOL;
?>
