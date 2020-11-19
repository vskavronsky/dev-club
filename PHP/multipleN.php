<?php
    define("START", 0);

    $limit = fgets(STDIN);
    $divisor = fgets(STDIN);
    
    if ( $divisor < 0 ) {
        $divisor *= -1;
    }
    
    echo implode(' ', range(START, $limit, $divisor)) . PHP_EOL;
?>
