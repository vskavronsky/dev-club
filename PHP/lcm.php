<?php
    function gcd($a, $b) {
        if ( $b == 0 ) {
            return $a;
        }
        return gcd($b, $a % $b);
    }

    function lcm($x, $y) {
        return $x / gcd($x, $y) * $y;
    }
    
    $in = fopen("lcmIn.txt", "r");
    $out = fopen("lcmOut.txt", "w");
    
    $numbers = fscanf($in, "%d %d");
    $first = $numbers[0];
    $second = $numbers[1];
    
    fprintf($out, "%d\n", lcm($first, $second));
    
    fclose($in);
    fclose($out);
?>
