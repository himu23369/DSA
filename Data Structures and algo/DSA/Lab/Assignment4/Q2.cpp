// Reverse a string using stack

#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main()
{
    int count = 0;
    string str;
    cout << "Enter the string that you want to reverse" << endl;
    getline(cin, str);

    stack<char> s;

    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] != ' ')
        {
            s.push(str[i]);
            count++;
        }
    }

    string ans;
    for (int i = 0; i < count; i++)
    {
        char top = s.top();
        ans = ans + top;
        s.pop();
    }

    cout << ans;

    return 0;
}