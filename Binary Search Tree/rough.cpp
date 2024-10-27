#include <climits>
#include <cmath>
#include <queue>
#include "BinaryTreeNode.h"
#include <iostream>
using namespace std;

BinaryTreeNode<int> *takeInputLevelWise() // Iterative approach
{
    int rootData;
    cout << "Enter root data" << endl;
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

        int leftChildData;
        cout << "Enter data for left child of " << front->data << endl;
        cin >> leftChildData;
        if (leftChildData != -1)
        {
            BinaryTreeNode<int> *leftChild = new BinaryTreeNode<int>(leftChildData);
            front->left = leftChild;
            pendingNodes.push(leftChild);
        }

        int rightChildData;
        cout << "Enter data for right child of " << front->data << endl;
        cin >> rightChildData;
        if (rightChildData != -1)
        {
            BinaryTreeNode<int> *rightChild = new BinaryTreeNode<int>(rightChildData);
            front->right = rightChild;
            pendingNodes.push(rightChild);
        }
    }
    return root;
}

bool searchInBST(BinaryTreeNode<int> *root, int k)
{
    if (root == NULL)
    {
        return false;
    }

    else if (root->data == k)
    {
        return true;
    }

    else if (root->data < k)
    {
        return searchInBST(root->right, k);
    }

    else if (root->data > k)
    {
        return searchInBST(root->left, k);
    }
}

void elementsInRangeK1K2(BinaryTreeNode<int> *root, int k1, int k2)
{
    if (root == NULL)
    {
        return;
    }

    if (root->data < k1)
    {
        elementsInRangeK1K2(root->right, k1, k2);
    }

    else if (root->data > k2)
    {
        elementsInRangeK1K2(root->left, k1, k2);
    }

    else if (root->data > k1 && root->data < k2)
    {
        elementsInRangeK1K2(root->left, k1, k2);
        cout << root->data << " ";
        elementsInRangeK1K2(root->right, k1, k2);
    }
}

int maximum(BinaryTreeNode<int> *root)
{
    int leftMax = maximum(root->left);
    int rightMax = maximum(root->right);
    return max(root->data, leftMax, rightMax);
}

int minimum(BinaryTreeNode<int> *root)
{
    int leftMax = minimum(root->left);
    int rightMax = minimum(root->right);
    return min(root->data, leftMax, rightMax);
}

bool isBST(BinaryTreeNode<int> *root)
{
}

void printLevelWiseData(BinaryTreeNode<int> *root)
{
    BinaryTreeNode<int> *temp = new BinaryTreeNode<int>(-1);

    queue<BinaryTreeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    pendingNodes.push(temp);

    while (pendingNodes.size() != 0)
    {
        BinaryTreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();

        if (front == temp)
        {
            if (pendingNodes.size() == 0)
            {
                return;
            }
            cout << endl;
            pendingNodes.push(temp);
            continue;
        }

        cout << front->data << " ";

        if (front->left)
        {
            pendingNodes.push(front->left);
        }

        if (front->right)
        {
            pendingNodes.push(front->right);
        }
    }
    delete temp;
}

/*
45 35 68 15 42 64 78 -1 -1 -1 -1 -1 -1 -1 -1
*/

int main()
{
    BinaryTreeNode<int> *root = takeInputLevelWise();
    printLevelWiseData(root);
    cout << endl;

    /*
    int x;
    while (x >= 0)
    {
        cout << "Enter data to be found" << endl;
        cin >> x;
        cout << "RESULT:" << searchInBST(root, x) << endl
             << endl;
    }
    */

    /*
    int f = 0;
    while (f != -1)
    {
        int a, b;
        cout << "Enter the range" << endl;
        cout << "a: ";
        cin >> a;
        cout << "b: ";
        cin >> b;
        cout << "Elements in range " << a << " and " << b << ": ";
        elementsInRangeK1K2(root, a, b);

        cout << endl
             << "Do you wish to continue?" << endl;
        cin >> f;
    }
    */

    cout << "MAXIMUM VALUE: " << maximum(root) << endl;
    cout << "MINIMUM VALUE: " << minimum(root) << endl
         << endl;

    return 0;
}