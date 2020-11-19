<?php
    $size = fgets(STDIN);
    
    for ( $column = 1; $column <= $size; $column++ ) {
        for ( $row = 1; $row < $size; $row++ ) {
            echo $row . ' ';
        }
        // echo $size . PHP_EOL; # for apple, linux 
        echo $size; # for windows
    }
?>
