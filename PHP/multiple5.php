<?php
    define("START", 0);
    define("MULTIPLE", 5);
    
    $limit = fgets(STDIN);
    
    echo implode(' ', range(START, $limit, MULTIPLE)) . PHP_EOL;
?>
