<?php
    define("START", 0);
    define("EVEN_STEP", 2);

    $limit = fgets(STDIN);
    
    echo implode(' ', range(START, $limit, EVEN_STEP)) . PHP_EOL;
?>
