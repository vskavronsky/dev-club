<?php
    require_once 'Passport.php';
    
    try {
        $pass = new Passport("Bret", "Pit", "03/21/1984");
        $pass2 = new Passport("Bob", "Rough", "07/19/1614");
        
        $pass->firstName = 'Ololo';
        $pass->secondName = 'Trololo';
        $pass->birthDate = '11/24/3047';
        
        Passport::setNewSeries('BC');
        
        $pass3 = new Passport("Anton", "Pup", "10/01/1997");
        $pass4 = new Passport("Simon", "Mex", "06/13/2005");
        $pass5 = new Passport("Roman", "Omovich", "12/31/2012");
        
        Passport::setNewSeries('DA', 300000);
        
        $pass6 = new Passport("Poberto", "Arkadievich", "02/22/2922");
        $pass6 = new Passport("Huanita", "Kon", "11/26/1897");
        
        Passport::getAllPassports();
        
    } catch ( InvalidAttribute $ex ) {
        echo $ex->getMessage() . PHP_EOL;
    } catch ( InvalidNewSeries $ex ) {
        echo $ex->getMessage() . PHP_EOL;
    } catch ( InvalidParam $ex ) {
        echo $ex->getMessage() . PHP_EOL;
    } catch ( InvalidPassportNumber $ex ) {
        echo $ex->getMessage() . PHP_EOL;
    } catch ( PassportNotFound $ex ) {
        echo $ex->getMessage() . PHP_EOL;
    } catch ( ReachedLimit $ex ) {
        echo $ex->getMessage() . PHP_EOL;
    } catch ( SeriesLengthExceeded $ex ) {
        echo $ex->getMessage() . PHP_EOL;
    }
?>
