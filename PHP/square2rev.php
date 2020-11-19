<?php
    $size = fgets(STDIN);

    for ( $column = 0, $total = $size * $size; $column < $size; $column++ ) {
        for ( $row = 1, $counter = $total - $size; $row < $size; $row++ ) {
            $counter += 1;
            echo $counter . ' ';
        }
        echo $total . PHP_EOL;
        $total -= $size;
    }
?>
