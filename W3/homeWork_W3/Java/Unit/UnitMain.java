public class UnitMain {
    public static void main(String[] args) {
        try {
            Unit barbarian = new Unit("Barbarian", 200, 40);
            Unit knight = new Unit("Zombie", 50, 20);
            
            // cout << barbarian << "\n" << endl;
            // cout << knight << "\n" << endl;
            
            // for ( int i = 0; i < 5; i++ ) {          
            barbarian.attack(knight);
            System.out.println(barbarian + "\n");
            System.out.println(knight + "\n");
                
            knight.addHitPoints(20);
            System.out.println(barbarian + "\n");
            System.out.println(knight + "\n"); 
                
            // knight.counterAttack(barbarian);
            // cout << barbarian << "\n" << endl;
            // cout << knight << "\n" << endl;
            // }
        }
        catch (UnitIsDeadException exception) {
            System.out.println("Your warrior is dead.");
        }
    }
}
