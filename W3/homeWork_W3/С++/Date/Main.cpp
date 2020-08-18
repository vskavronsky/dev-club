#include "Date.h"

using namespace std;

int main() {
    try {
        Date date1(3, 1, 1742);
        cout << "Leap 01 - " << date1 << endl;
        Date date2(31, 01, 1674);
        cout << "noLeap 01 -" << date2 << endl;
        
        cout << "-----------------------" << endl;
        
        Date date3(29, 02, 2000);
        cout << "Leap 02 - " << date3 << endl;
        Date date4(28, 02, 1891);
        cout << "noLeap 02 -" << date4 << endl;
        
        cout << "-----------------------" << endl;
        
        Date date5(31, 03, 2000);
        cout << "Leap 03 -" << date5 << endl;
        Date date6(31, 03, 2003);
        cout << "noLeap 03 -" << date6 << endl;
        
        cout << "-----------------------" << endl;
        
        Date date7(16, 04, 2000);
        cout << "Leap 04 - " << date7 << endl;
        Date date8(30, 04, 2003);
        cout << "noLeap 04 -" << date8 << endl;
        
        cout << "-----------------------" << endl;
        
        Date date9(31, 05, 2000);
        cout << "Leap 05 - " << date9 << endl;
        Date date10(31, 05, 2003);
        cout << "noLeap 05 -" << date10 << endl;
        
        cout << "-----------------------" << endl;
        
        Date date11(30, 06, 2000);
        cout << "Leap 06 -" << date11 << endl;
        Date date12(30, 06, 2003);
        cout << "noLeap 06 -" << date12 << endl;
        
        cout << "-----------------------" << endl;
        
        Date date13(31, 07, 2000);
        cout << "Leap 07 - " << date13 << endl;
        Date date14(31, 07, 2003);
        cout << "noLeap 07 -" << date14 << endl;
        
        cout << "-----------------------" << endl;
        
        Date date15(31, 8, 2000);
        cout << "Leap 08 - " << date15 << endl;
        Date date16(31, 8, 2003);
        cout << "noLeap 08 -" << date16 << endl;
        
        cout << "-----------------------" << endl;
        
        Date date17(30, 9, 2000);
        cout << "Leap 09 -" << date17 << endl;
        Date date18(30, 9, 2003);
        cout << "noLeap 09 -" << date18 << endl;
        
        cout << "-----------------------" << endl;
        
        Date date19(31, 10, 2000);
        cout << "Leap 10 - " << date19 << endl;
        Date date20(31, 10, 2003);
        cout << "noLeap 10 -" << date20 << endl;
        
        cout << "-----------------------" << endl;
        
        Date date21(30, 11, 2000);
        cout << "Leap 11 - " << date21 << endl;
        Date date22(30, 11, 2003);
        cout << "noLeap 11 -" << date22 << endl;
        
        cout << "-----------------------" << endl;
        
        Date date23(31, 12, 2000);
        cout << "Leap 12 -" << date23 << endl;
        Date date24(31, 12, 2003);
        cout << "noLeap 12 -" << date24 << endl;
        
    }
    catch ( const InvalidDate& exception ) {
        cout << exception.text << endl;
    }
    
    return 0;
}
