<?php
    function arrayShiftRight(&$array) {
        $size = count($array);
        $last = $size - 1;
        $first = $array[$last];
    
        for ( ; $last > 0; $last-- ) {
            $array[$last] = $array[$last-1];
        }
        $array[0] = $first;
    }
    
    $arr = array(9, 8, 7, 6, 5, 4, 3, 2, 1);
    
    $count = 5;
    for ( ; $count > 0; $count-- ) {
        arrayShiftRight($arr);   
    }
    
    print_r($arr);
?>
