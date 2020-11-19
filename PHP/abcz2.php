<?php
    $val = fgets(STDIN);
    $isZulu = true;
    
    if ( $val % 2 == 0 ) {
        echo "alpha" . PHP_EOL;
        $isZulu = false;
    }
    if ( $val % 3 == 0 ) {
        echo "bravo" . PHP_EOL;
        $isZulu = false;
    }
    if ( $val % 5 == 0 ) {
        echo "charlie" . PHP_EOL;
        $isZulu = false;
    }
    if ( $isZulu ) {
        echo "zulu" . PHP_EOL;
    }
?>
