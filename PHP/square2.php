<?php
    $size = fgets(STDIN);

    for ( $column = 0, $counter = 1; $column < $size; $column++ ) {
        for ( $row = 1; $row < $size; $row++ ) {
            echo $counter . ' ';
            $counter += 1;
        }
        echo $counter . PHP_EOL;
        $counter += 1;
    }
?>
