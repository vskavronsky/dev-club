<?php
    define("START", 0);
    define("MULTIPLE", 3);
    
    $limit = fgets(STDIN);
    
    echo implode(' ', range(START, $limit, MULTIPLE)) . PHP_EOL;
?>
