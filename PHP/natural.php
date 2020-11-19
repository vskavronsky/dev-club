<?php
    define("START", 1);

    $limit = fgets(STDIN);
    
    echo implode(' ', range(START, $limit)) . PHP_EOL;
?>
