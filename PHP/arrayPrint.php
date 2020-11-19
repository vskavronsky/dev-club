<?php
    function arrayPrint($out, $array) {
        $outArray = implode(" ", $array) . PHP_EOL;
        fwrite($out, $outArray);
    }
    
    $out = fopen("arrayPrint.txt", "w");
    
    $arr = array(10, 20, 30, 40, 50);
    $arr2 = array(31, 42, 73, 64, 56);
    
    arrayPrint($out, $arr);
    arrayPrint($out, $arr2);
    
    fclose($out);
?>
