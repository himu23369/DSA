#include "TrieNode.h"
#include <string>

class Trie
{
  TrieNode *root;

public:
  Trie()
  {
    root = new TrieNode('\0');
  }

  void insertWord(TrieNode *root, string word)
  {
    // Base case
    if (word.size() == 0)
    {
      root->isTerminal = true;
      return;
    }

    // Small Calculation
    int index = word[0] - 'a';
    TrieNode *child;
    if (root->children[index] != NULL)
    {
      child = root->children[index];
    }
    else
    {
      child = new TrieNode(word[0]);
      root->children[index] = child;
    }

    // Recursive call
    insertWord(child, word.substr(1));
  }

  // For user
  void insertWord(string word)
  {
    insertWord(root, word);
  }

  void removeWord(TrieNode *root, string word)
  {
    // Base case
    if (word.size() == 0)
    {
      root->isTerminal = false;
      return;
    }
    // Small Calculation
    TrieNode *child;
    int index = word[0] - 'a';
    if (root->children[index] != NULL)
    {
      child = root->children[index];
    }

    else
    {
      // Word not found
      return;
    }

    removeWord(child, word.substr(1));

    // Remove Child node if it is useless
    if (child->isTerminal == false)
    {
      for (int i = 0; i < 26; i++)
      {
        if (child->children[i] != NULL)
        {
          return;
        }
      }
      delete child;
      root->children[index] = NULL;
    }
  }

  void removeWord(string word)
  {
    removeWord(root, word);
  }
};
