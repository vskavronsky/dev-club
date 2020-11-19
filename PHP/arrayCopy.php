<?php
    $initial = array(1, 2, 3, 4, 5, 6, 7, 8);
    $copy = array();
    
    foreach ($initial as $value) {
        array_push($copy, $value);
    }
    
    print_r($initial);
    print_r($copy);
?>
