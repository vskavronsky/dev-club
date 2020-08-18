public class GunMain {
    public static void main(String[] args) {
        try {
            // Gun gun;
            Gun uzi = new Gun();
            
            // cout << gun << endl;
            System.out.println(uzi);
            
            uzi.reload();
            uzi.prepare();
        
            for ( int i = 0; i < 5; i++ ) {
                uzi.shoot();
            } 
            
            uzi.reload();
            System.out.println(uzi);
            
            for ( int i = 0; i < 30; i++ ) {
                uzi.shoot();
            } 
            // cout << gun << endl;
            System.out.println(uzi);
            uzi.reload();
            uzi.shoot();
            
            System.out.println(uzi);
        } catch (NotReadyException exception) {
            System.out.println("Please, prepare for shooting!");
        } catch (OutOfRoundsException exception) {
            System.out.println("Please, reload your gun to continue shooting!");
        }
    }
}
