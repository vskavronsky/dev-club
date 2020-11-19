<?php
    function arrayScan($in, $length) {
        $outArray = fread($in, $length);
        $arrayElem = explode(" ", $outArray);
        
        return count($arrayElem);
    }
    
    $length = 1024;
    $in = fopen("arrayScan.txt", "r");
    
    echo arrayScan($in, $length) . PHP_EOL;
    
    fclose($in);
?>
