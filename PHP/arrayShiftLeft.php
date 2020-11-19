<?php
    function arrayShiftLeft(&$array) {
        $size = count($array);
        $temp = $array[0];
    
        for ( $i = 1; $i < $size; $i++ ) {
            $array[$i-1] = $array[$i];
        }
        $array[$size-1] = $temp;
    }
    
    $arr = array(9, 8, 7, 6, 5, 4, 3, 2, 1);
    
    $count = 4;
    for ( ; $count > 0; $count-- ) {
        arrayShiftLeft($arr);   
    }
    
    print_r($arr);
?>
