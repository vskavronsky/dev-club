<?php
    $a = fgets(STDIN);
    $b = fgets(STDIN);
    $c = fgets(STDIN);
    $isZulu = true;
    
    if ( $a + $b > $c ) {
        echo "alpha" . PHP_EOL;
        $isZulu = false;
    }
    if ( $a < $b - $c ) {
        echo "bravo" . PHP_EOL;
        $isZulu = false;
    }
    if ( $b % $c == 0 ) {
        echo "charlie" . PHP_EOL;
        $isZulu = false;
    } 
    if ( $isZulu ) {
        echo "zulu" . PHP_EOL;
    }
?>
