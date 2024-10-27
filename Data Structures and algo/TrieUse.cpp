//We used Trie over heap for making dictionary bcos of space optimization and faster searching.

#include <iostream>
using namespace std;
#include "Trie.h"

int main()
{

    Trie t;
    t.insertWord("and");
    t.insertWord("are");

    // cout << t.search("and") << endl;

    t.removeWord("and");


    return 0;
}