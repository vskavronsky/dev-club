<?php
    $arr = array(0 => 'blue', 1 => 'red', 2 => 'green', 3 => 'red', 4 => 'black');
    
    $key1 = array_search('red', $arr);
    $key2 = array_search('black', $arr);
    $key3 = array_search('orange', $arr);
    
    if ( $key3 == false ) {
        $key3 = 'false';
    }
    
    echo 'key for red - ' . $key1 . PHP_EOL;
    echo 'key for black - ' . $key2 . PHP_EOL;
    echo 'key for orange - ' . $key3 . PHP_EOL;
?>
