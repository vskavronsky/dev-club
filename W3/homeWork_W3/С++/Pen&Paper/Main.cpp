#include "Pen.h"

using namespace std;

int main() {
    try {
        Pen pen(400);
        Paper paper(300);
        string str1 = "Hello World! I love C++ so much.";
        string str2 = "\nBut he loves Java.";
        
        pen.refill();
        pen.write(paper, str1);
        paper.show();
        
        cout << "inkAmount - " << pen.getInkAmount() << endl;
        cout << "inkCapacity - " << pen.getInkCapacity() << endl;
        cout << "symbols - " << paper.getSymbols() << endl;
        cout << "maxSymbols - " << paper.getMaxSymbols() << endl;
        
        pen.write(paper, str2);
        paper.show();
        
        cout << "inkAmount - " << pen.getInkAmount() << endl;
        cout << "inkCapacity - " << pen.getInkCapacity() << endl;
        cout << "symbols - " << paper.getSymbols() << endl;
        cout << "maxSymbols - " << paper.getMaxSymbols() << endl;
        
        pen.write(paper, str1);
        paper.show();
        
        cout << "inkAmount - " << pen.getInkAmount() << endl;
        cout << "inkCapacity - " << pen.getInkCapacity() << endl;
        cout << "symbols - " << paper.getSymbols() << endl;
        cout << "maxSymbols - " << paper.getMaxSymbols() << endl;
        
        // pen.write(paper, str);
        // paper.show();
        
        // cout << "inkAmount - " << pen.getInkAmount() << endl;
        // cout << "inkCapacity - " << pen.getInkCapacity() << endl;
        // cout << "symbols - " << paper.getSymbols() << endl;
        // cout << "maxSymbols - " << paper.getMaxSymbols() << endl;
    }
    catch ( const OutOfInk& exception ) {
        cout << "Please, refill your pen!" << endl;
    }
    catch ( const OutOfSpace& exception ) {
        cout << "Not enough space! You used all free space on the paper!" << endl;
    }
    
    return 0;
}
