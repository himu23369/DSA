#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> v;

void check(string s, int start, int end)
{
    int st = start;
    int e = end;
    start++;
    end--;
    while (start < end)
    {
        if (s[start] == s[end])
        {
            start++;
            end--;
        }
        else
        {
            break;
        }
    }
    if (start >= end)
    {
        string palindrome = "";
        for (int i = st; i <= e; i++)
        {
            palindrome += s[i];
        }
        cout << "Returning Palindrome: " << palindrome << endl;
        v.push_back(palindrome);
    }
}

string longestPalindrome(string s)
{
    int len = s.size();
    for (int i = 0; i < len; i++)
    {
        for (int j = len - 1; j > i; j--)
        {
            if (s[i] == s[j])
            {
                cout << "i: " << i << " j: " << j << endl;
                check(s, i, j);
            }
        }
    }

    int index = -1;
    int x = 0;
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << v[i].size() << endl;
        if (v[i].length() >= x)
        {
            cout << "Holaa" << endl;
            index = i;
            x = v[i].size();
        }
    }
    cout << "Index and x: " << index << ","<< x << endl;
    return v[index];
}

int main()
{
    string s = "ac";
    string ans = longestPalindrome(s);
    cout << "Longest wali: " << ans;

    return 0;
}
