#include <iostream>
using namespace std;

int main()
{
    string s = "Bhavika";
    // getline(cin, s);
    cout << endl;
    cout << s << endl;
    cout << "Size of string is: " << s.size() << endl;

    string *s1 = new string;
    *s1 = "Himanshu";
    cout << s1 << endl; // will print the address
    cout << *s1 << endl;

    string s2;
    s2 = "Jennie";
    cout << s2 << endl;
    cout << s2[0] << endl; // Behaves just like an array
    s2[0] = 'S';           // We can change any character we want, control is in our hand
    cout << s2 << endl;

    string s3 = s + s2;
    cout << s3 << endl;
    s += s3;
    cout << s << endl;

    // Substring has 2 variations
    cout << s.substr(3) << endl;
    cout << s.substr(3, 3) << endl;

    // For finding purpose
    cout << s.find("vik") << endl;

    return 0;
}