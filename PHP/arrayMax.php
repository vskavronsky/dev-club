<?php
    function arrayMax($array) {
        $size = count($array);
        $max = $array[0];
        
        for ( $i = 1; $i < $size; $i++ ) {
            if ( $max < $array[$i] ) {
                $max = $array[$i];
            }
        }
        return $max;
    }
    
    $arr = array(2, 1, 3, 7, 9, 4, 12, 5);
    
    echo "max number of the array - " . arrayMax($arr) . PHP_EOL;
?>
