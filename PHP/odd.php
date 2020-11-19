<?php
    define("START", 1);
    define("ODD_STEP", 2);

    $limit = fgets(STDIN);
    
    echo implode(' ', range(START, $limit, ODD_STEP)) . PHP_EOL;
?>
