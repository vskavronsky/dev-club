#include "Unit.h"

using namespace std;

int main() {
    try {
        Unit barbarian("Barbarian", 200, 40);
        Unit knight("Knight", 100, 60);
        
        // cout << barbarian << "\n" << endl;
        // cout << knight << "\n" << endl;
        
        // for ( int i = 0; i < 5; i++ ) {          
            barbarian.attack(knight);
            cout << barbarian << "\n" << endl;
            cout << knight << "\n" << endl;
            
            knight.addHitPoints(20);
            cout << barbarian << "\n" << endl;
            cout << knight << "\n" << endl;  
            
            // knight.counterAttack(barbarian);
            // cout << barbarian << "\n" << endl;
            // cout << knight << "\n" << endl;
        // }
    }
    catch ( const UnitIsDead& exception ) {
        cout << "Your warrior is dead." << endl;
    }
    
    return 0;    
}
