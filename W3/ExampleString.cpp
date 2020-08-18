#include <iostream>
#include <string>

using namespace std;

int main() {
    string name, surname;
    
    name = "Vitalii";
    surname = "Skavronskyi";
    
    name += " M.";
    name.push_back('\n');
    name += surname;
    name += '\n';
    
    // char buffer[10];
    string str;
    string base = "The quick brown fox jumps over a lazy dog.";

    // used in the same order as described above:
    
    // base.copy(buffer, 10, 9);
    // cout << buffer << endl;
    
    // cout << "Enter your full name:";
    // cin >> name;
    // cout << name << endl;
    
    // cout << "Enter your full name:";
    // getline(cin, name);
    // cout << name << endl;
    
    cout << base.compare(surname) << endl; // 1
    
    str = base.substr(0, 19);
    cout << str << endl;
    
    str = base.substr(16);
    cout << str << '\n';
    
    int found = base.find("cat"); 
    cout << found << endl; // -1
    
    str = base.c_str();
    cout << str << endl;
    
    cout << name << endl;
    cout << surname << endl;
    
    name.swap(surname);
    
    cout << name << endl;
    cout << surname << endl;
    
    name.assign(base);
    cout << name << '\n';
    
    name.insert(32, " fat");
    cout << name << '\n';
    
    name.erase(3, 12);
    cout << name << endl;
    
    name.replace(3, 4, " slim yellow jaguar");
    cout << name << endl;
    
    str.assign(base, 10, 9);
    cout << str << '\n';         // "brown fox"

    str.assign("pangrams are cool", 7);
    cout << str << '\n';         // "pangram"

    str.assign("c-string");
    cout << str << '\n';         // "c-string"

    str.assign(10,'*');
    cout << str << '\n';         // "**********"

    str.assign<int>(10,0x2D);
    cout << str << '\n';         // "----------"

    str.assign(base.begin()+16,base.end()-12);
    cout << str << '\n';         // "fox jumps over"
    
    string str1;
    string str2 = "Writing ";
    string str3 = "print 10 and then 5 more";

    // used in the same order as described above:
    str1.append(str2);                       // "Writing "
    str1.append(str3,6,3);                   // "10 "
    str1.append("dots are cool",5);          // "dots "
    str1.append("here: ");                   // "here: "
    str1.append(10,'.');                     // ".........."
    str1.append(str3.begin()+8,str3.end());  // " and then 5 more"
    str1.append<int>(5,0x2E);                // "....."

    cout << str1 << '\n';
    
    cout << name << endl;
    cout << "name size - " << name.size() << endl;
    cout << "name length - " << name.length() << endl;
    cout << "name capacity - " << name.capacity() << endl;
    cout << "name max_size - " << name.max_size() << endl;
    
    // str3.resize(20,'-');
    // cout << str3 << endl;
    
    cout << "isEmpty - " << name.empty() << endl; // return 1, if length = 0
    
    int last = name.length() - 1;
    for ( int i = 0; i < last; i++ ) {
        cout << name[i];
    }
    cout << name[last] << endl;
    
    for ( int i = 0; i < name.length(); i++ ) {
        cout << name.at(i); // check massive bonders
    }
    
    return 0;    
}
