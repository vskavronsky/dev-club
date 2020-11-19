<?php
    function arrayMin($array) {
        $size = count($array);
        $min = $array[0];
        
        for ( $i = 1; $i < $size; $i++ ) {
            if ( $min > $array[$i] ) {
                $min = $array[$i];
            }
        }
        return $min;
    }
    
    $arr = array(2, 1, 3, 0, 9, -4, 12, 5);
    
    echo "min number of the array - " . arrayMin($arr) . PHP_EOL;
?>
