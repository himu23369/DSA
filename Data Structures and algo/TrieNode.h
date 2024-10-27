/*
int * a = new int[10];  --> Isme a pointer ek integer type variable ka address store kar rha hai
int ** b = new int * [10]; --> Isme b pointer ek int * type ka address store kar rha hai
*/

#include <iostream>
using namespace std;

class TrieNode
{
public:
    char data;
    TrieNode **children;
    bool isTerminal;

    TrieNode(char data)
    {
        this->data = data;
        children = new TrieNode *[26];
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};
