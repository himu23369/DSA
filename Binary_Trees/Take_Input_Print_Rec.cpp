#include <iostream>
#include <queue>
#include <stack>
#include "BinaryTreeNode.h"
using namespace std;

BinaryTreeNode<int> *takeInput() // Recursive method
{
    int rootData;
    cout << "Enter root data" << endl;
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

// Count nodes
int numNodes(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return 0;
    }

    return 1 + numNodes(root->left) + numNodes(root->right);
}

// Find whether node with data X exists or not
bool isNodePresent(BinaryTreeNode<int> *root, int x)
{
    if (root == NULL)
    {
        return false;
    }

    if (root->data == x)
    {
        return true;
    }

    bool leftTree = isNodePresent(root->left, x);
    bool rightTree = isNodePresent(root->right, x);

    return (leftTree || rightTree);
}

// Height of Binary tree
int height(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int leftTreeHeight = height(root->left);
    int rightTreeHeight = height(root->right);

    return 1 + max(leftTreeHeight, rightTreeHeight);
}

// Remove Leaf Nodes
BinaryTreeNode<int> *removeLeafNodes(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return NULL;
    }

    if (root->left == NULL && root->right == NULL)
    {
        return NULL;
    }

    BinaryTreeNode<int> *leftPart = removeLeafNodes(root->left);
    BinaryTreeNode<int> *rightPart = removeLeafNodes(root->right);

    root->left = leftPart;
    root->right = rightPart;

    return root;
}

// Print all nodes without siblings
void printNodesWithoutSibling(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }

    if (root->left != NULL && root->right == NULL)
    {
        cout << root->left->data << " ";
    }

    else if (root->right != NULL && root->left == NULL)
    {
        cout << root->right->data << " ";
    }

    printNodesWithoutSibling(root->left);
    printNodesWithoutSibling(root->right);
}

// ZigZag Tree
void zigZagOrder(BinaryTreeNode<int> *root)
{
    // Write your code here
    if (!root)
        return;

    stack<BinaryTreeNode<int> *> s1;
    stack<BinaryTreeNode<int> *> s2;

    s1.push(root);

    while (!s1.empty() && !s2.empty())
    {
        while (!s1.empty())
        {
            BinaryTreeNode<int> *top = s1.top();
            s1.pop();
            cout << top->data << " ";

            if (top->left)
                s2.push(top->left);
            if (top->right)
                s2.push(top->right);
        }

        cout << endl;

        while (!s2.empty())
        {
            BinaryTreeNode<int> *top = s2.top();
            s2.pop();
            cout << top->data << " ";

            if (top->right)
                s1.push(top->right);
            if (top->left)
                s1.push(top->left);
        }
        cout << endl;
    }
}

// Mirror of Binary Tree
void mirrorBinaryTree(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }

    BinaryTreeNode<int> *temp = root->right;
    root->right = root->left;
    root->left = temp;

    mirrorBinaryTree(root->left);
    mirrorBinaryTree(root->right);
}

// PreOrder Traversal -> First root node is visited, then left subtree is traversed recursively and then right
void preOrder(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }

    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

// PostOrder Traversal -> Left, Right and then root
void postOrder(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }

    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

// Construct tree from Preorder and Inorder
// Construct tree from Postorder and Inorder

// Sum of nodes data for Binary Tree
int sumOfNodes(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return (root->data) + sumOfNodes(root->left) + sumOfNodes(root->right);
}

// Print tree in level order fashion
// 1 2 3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1
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

void printLevelWise(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }

    queue<BinaryTreeNode<int> *> pendingNodes;
    pendingNodes.push(root);

    while (pendingNodes.size() != 0)
    {
        BinaryTreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();

        cout << "Root:" << front->data << endl;

        if (front->left)
        {
            cout << "L:" << front->left->data << " ";
            pendingNodes.push(front->left);
        }
        else
        {
            cout << "L:" << -1 << " ";
        }

        if (front->right)
        {
            cout << "R:" << front->right->data << endl;
            pendingNodes.push(front->right);
        }
        else
        {
            cout << "R:" << -1 << endl;
        }
    }
}

void printTree(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }

    cout << "Root:" << root->data << endl;

    if (root->left)
    {
        cout << "L:" << root->left->data << " ";
    }
    else
    {
        cout << "L:" << -1 << " ";
    }

    if (root->right)
    {
        cout << "R:" << root->right->data << endl;
    }
    else
    {
        cout << "R:" << -1 << endl;
    }

    printTree(root->left);
    printTree(root->right);
}

// 1 2 3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1

int main()
{
    BinaryTreeNode<int> *root = takeInputLevelWise();

    cout << "LEVEL WISE PRINTING: " << endl;
    printLevelWise(root);
    cout << endl;

    cout << "HEIGHT OF BINARY TREE:" << height(root) << endl
         << endl;
    cout << "NUMBER OF NODES:" << numNodes(root) << endl
         << endl;

    cout << "PREORDER TRAVERSAL:" << endl;
    preOrder(root);
    cout << endl
         << endl;

    cout << "POSTORDER TRAVERSAL:" << endl;
    postOrder(root);
    cout << endl
         << endl;

    cout << "SUM OF NODES:" << sumOfNodes(root) << endl
         << endl;

    cout << "LEVEL WISE DATA PRINTING: " << endl;
    printLevelWiseData(root);
    cout << endl;

    cout << "NODES WITHOUT SIBLINGS:" << endl;
    printNodesWithoutSibling(root);
    cout << endl;

    cout << "ZIGZAG TREE: " << endl;
    zigZagOrder(root);
    cout << endl;

    cout << "AFTER REMOVING LEAF NODES:" << endl;
    removeLeafNodes(root);
    printLevelWiseData(root);
    cout << endl;
    /*
    mirrorBinaryTree(root);
    cout << "LEVEL WISE PRINTING AFTER MIRRORING: " << endl;
    printLevelWise(root);
    cout << endl;
    */

    /*
        int x;
        while (x != -1)
        {
            cout << "Enter node data to find || Enter -1 to exit" << endl;
            cin >> x;
            cout << "Node Present/Absent: " << isNodePresent(root, x) << endl;
        }

     */
    return 0;
}