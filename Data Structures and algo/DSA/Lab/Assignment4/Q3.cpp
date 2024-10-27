// Convert Infix to Postfix

/*
Precedence Order: (), ^[R -> L] ,* /[L -> R] , + -[L -> R]
*/

#include <iostream>
#include <stack>
using namespace std;

int main()
{
   string infix = " ";
   string postfix = " ";
   int i = 0;

   cout << "Enter the Infix Expression" << endl;
   cin >> infix;

   stack<char> s;

   while (infix[i] != '\0')
   {
      if ((infix[i] >= 'a' && infix[i] <= 'z') || (infix[i] >= 'A' && infix[i] <= 'Z'))
      {
         postfix = postfix + infix[i];
         // cout << "I am called" << endl;
      }

      else if (infix[i] == '(')
      {
         s.push(infix[i]);
         // cout << "I am called" << endl;
      }

      else if (infix[i] == ')')
      {
         if (s.top() == '(')
         {
            s.pop();
         }
         else
         {
            s.push(infix[i]);
         }
         // cout << "I am called" << endl;
      }

      else if (infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/' || infix[i] == '^')
      {
         cout << "hello" << endl;

         if (s.top() == '+' || s.top() == '-' || s.top() == '*' || s.top() == '/' || s.top() == '^')
         {
            cout << "hello" << endl;
            postfix = postfix + s.top();
            cout << postfix << endl;
            s.pop();
         }
         else
         {
            s.push(infix[i]);
            cout << "hello" << endl;
         }
      }
      s.pop();
      i++;
   }

   // cout << postfix << endl;

   return 0;
}