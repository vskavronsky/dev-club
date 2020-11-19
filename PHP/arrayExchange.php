<?php
    function arrayExchange(&$array) {
        $size = count($array);
        
        for ( $i = 1; $i < $size; $i += 2 ) {
            $temp = $array[$i];
        
            $array[$i] = $array[$i-1];
            $array[$i-1] = $temp;
        }
    }
    
    $arr = array(2, 1, 4, 3, 6, 5, 7);
    
    arrayExchange($arr);
    
    print_r($arr);
?>
