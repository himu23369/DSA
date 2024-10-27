// Binary Trees -> Trees where every node has max 2 children
#include <iostream>
#include "BinaryTreeNode.h"
#include <queue>

using namespace std;

BinaryTreeNode<int> *takeInputLevelWise()
{
    int rootData;
    cout << "Enter data" << endl;
    cin >> rootData;

    if (rootData == -1)
    {
        return NULL;
    }

    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);

    queue<BinaryTreeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    while (pendingNodes.size() != 0)
    {
        BinaryTreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();

        cout << "Enter left child of " << front->data << endl;
        int leftChildData;
        cin >> leftChildData;
        if (leftChildData != -1)
        {
            BinaryTreeNode<int> *child = new BinaryTreeNode<int>(leftChildData);
            front->left = child;
            pendingNodes.push(child);
        }

        cout << "Enter right child of " << front->data << endl;
        int rightChildData;
        cin >> rightChildData;
        if (rightChildData != -1)
        {
            BinaryTreeNode<int> *child = new BinaryTreeNode<int>(rightChildData);
            front->right = child;
            pendingNodes.push(child);
        }
    }
    return root;
}

void inorder(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout << root->data;
    inorder(root->right);
}

int numNodes(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return 0;
    }

    return 1 + numNodes(root->left) + numNodes(root->right);
}

// Time Complexity of height is O(n)
int height(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return 0;
    }

    return 1 + max(height(root->left), height(root->right));
}
// To find the Time Complexity of diameter, we are considering two types of trees
/*  0
   0 0
0  0 0  0
This type of tree has number of nodes = log n
Time Complexity --> T(n) = Kn + 2T(n/2) where K is a constant, Kn is for height and other one is for right and left part
This is same as Merge Sort, so, Time Complexity is O(n logn)
*/

/*
  0
   0
    0
     0
      0
       0
This type of tree has number of nodes = n
For this, T(n) = Kn + T(n - 1)
This is the same reccurence relation as obtained for Bubble Sort
So, Time Complexity will be O(n*n)

So, we can say that overall Time c. will be O(n * height)
*/
int diameter(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int option1 = height(root->left) + height(root->right);
    int option2 = diameter(root->left);
    int option3 = diameter(root->right);

    return max(option1, max(option2, option3));
}

/*What was the problem here?
Actually, each node in 2nd example was calling multiple times the other node for diameter and height, i.e. was doing the work twice.
*/

// Better Approach
/*We will use in-built pair class*/
// Time Complexity of this will be O(n)
pair<int, int> heightDiameter(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        pair<int, int> p;
        p.first = 0;
        p.second = 0;
        return p;
    }

    pair<int, int> leftAns = heightDiameter(root->left);
    pair<int, int> rightAns = heightDiameter(root->right);
    int lh = leftAns.first;
    int ld = leftAns.second;
    int rh = rightAns.first;
    int rd = rightAns.second;

    int height = 1 + max(lh, rh);
    int diameter = max(lh + rh, max(ld, rd));
    pair<int, int> p;
    p.first = height;
    p.second = diameter;
    return p;
}

void printTree(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << ":";
    if (root->left != NULL)
    {
        cout << "L" << root->left->data;
    }

    if (root->right != NULL)
    {
        cout << "R" << root->right->data;
    }
    cout << endl;

    printTree(root->left);
    printTree(root->right);
}

BinaryTreeNode<int> *takeInput()
{
    int rootData;
    cout << "Enter data" << endl;
    cin >> rootData;

    if (rootData == -1)
    {
        return NULL;
    }

    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    BinaryTreeNode<int> *leftChild = takeInput();
    BinaryTreeNode<int> *rightChild = takeInput();
    root->left = leftChild;
    root->right = rightChild;
    return root;
}

int main()
{
    /* BinaryTreeNode<int> *root = new BinaryTreeNode<int>(1);
     BinaryTreeNode<int> *node1 = new BinaryTreeNode<int>(2);
     BinaryTreeNode<int> *node2 = new BinaryTreeNode<int>(3);

     root->left = node1;
     root->right = node2;*/

    BinaryTreeNode<int> *root = takeInputLevelWise();
    printTree(root);
    cout << "Num of nodes:" << numNodes(root);
    cout << endl;

    pair<int, int> ans = heightDiameter(root);
    cout << ans.first << " " << ans.second << endl;

    delete root;

    return 0;
}