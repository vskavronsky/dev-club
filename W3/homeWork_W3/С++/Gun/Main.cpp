#include "Gun.h"

using namespace std;

int main() {
    try {
        // Gun gun;
        Gun uzi("Uzi", 20);
        
        // cout << gun << endl;
        cout << uzi << endl;
        
        uzi.reload();
        uzi.prepare();
        
        for ( int i = 0; i < 20; i++ ) {
            uzi.shoot();
        } 
        
        uzi.reload();
        cout << uzi << endl;
        
        for ( int i = 0; i < 30; i++ ) {
            uzi.shoot();
        } 
        // cout << gun << endl;
        cout << uzi << endl;
        uzi.reload();
        uzi.shoot();
        
        cout << uzi << endl;
    }
    catch ( const NotReady& exception ) {
        cout << "Please, prepare for shooting!" << endl;
    } catch ( const OutOfRounds& exception ) {
        cout << "Please, reload your gun to continue shooting!" << endl;
    }
    
    return 0;
}
