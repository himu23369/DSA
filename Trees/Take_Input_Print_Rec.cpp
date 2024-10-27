#include <iostream>
#include <queue>
#include <stack>
#include "TreeNode.h"
#include <bits/stdc++.h>
using namespace std;

TreeNode<int> *takeInput()
{
    int rootData;
    cout << "Enter the data for root" << endl;
    cin >> rootData;
    TreeNode<int> *root = new TreeNode<int>(rootData);

    int numOfChildren;
    cout << "Enter number of children of " << rootData << endl;
    cin >> numOfChildren;

    for (int i = 0; i < numOfChildren; i++)
    {
        TreeNode<int> *child = takeInput();
        root->children.push_back(child);
    }

    return root;
}

TreeNode<int> *takeInputLevelWise()
{
    int rootData;
    cout << "Enter the data for root" << endl;
    cin >> rootData;
    TreeNode<int> *root = new TreeNode<int>(rootData);

    queue<TreeNode<int> *> pendingNodes;
    pendingNodes.push(root);

    while (pendingNodes.size() != 0)
    {
        TreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();

        int numChild;
        cout << "Enter the num of children of " << front->data << endl;
        cin >> numChild;
        for (int i = 0; i < numChild; i++)
        {
            int childData;
            cout << "Enter the data for " << i << "th child of " << front->data << endl;
            cin >> childData;
            TreeNode<int> *child = new TreeNode<int>(childData);
            front->children.push_back(child);

            pendingNodes.push(child);
        }
    }
    return root;
}

int totalNodes(TreeNode<int> *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int count = 1;
    for (int i = 0; i < root->children.size(); i++)
    {
        count += totalNodes(root->children[i]);
    }
    return count;
}

int sumOfNodes(TreeNode<int> *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int sum = root->data;
    for (int i = 0; i < root->children.size(); i++)
    {
        sum += sumOfNodes(root->children[i]);
    }
    return sum;
}

TreeNode<int> *maxDataNode(TreeNode<int> *root)
{
    if (root == NULL)
    {
        return NULL;
    }

    TreeNode<int> *max = new TreeNode<int>(root->data);

    for (int i = 0; i < root->children.size(); i++)
    {
        TreeNode<int> *child = maxDataNode(root->children[i]);
        if (child->data > root->data)
        {
            max = child;
        }
    }

    return max;
}

// Height of a tree is defined as the length of the path from the tree’s root node to any of it's leaf nodes.
int getHeight(TreeNode<int> *root)
{
    int h = 1;

    if (root->children.size() == 0)
        return h;

    int arr[root->children.size()];
    for (int i = 0; i < root->children.size(); i++)
    {
        arr[i] = getHeight(root->children[i]);
    }
    sort(arr, arr + root->children.size(), greater<int>());
    h += arr[0];

    return h;
}

void printAtLevelK(TreeNode<int> *root, int k)
{
    if (root == NULL)
    {
        return;
    }

    if (k == 0)
    {
        cout << root->data << " ";
    }

    for (int i = 0; i < root->children.size(); i++)
    {
        printAtLevelK(root->children[i], k - 1);
    }
}

// Post Order Traversal means print child nodes first and then root node
void printPostOrder(TreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }

    for (int i = 0; i < root->children.size(); i++)
    {
        printPostOrder(root->children[i]);
    }

    cout << root->data << " ";
}

int getLeafNodeCount(TreeNode<int> *root)
{
    if (root == NULL)
    {
        return 0;
    }

    if (root->children.size() == 0)
    {
        return 1;
    }

    int ans = 0;
    for (int i = 0; i < root->children.size(); i++)
    {
        ans += getLeafNodeCount(root->children[i]);
    }
    return ans;
}

// Given a generic tree, find if x is present or not
bool isPresent(TreeNode<int> *root, int x)
{
    if (root->data == x)
    {
        return true;
    }

    bool ans = false;
    for (int i = 0; i < root->children.size(); i++)
    {
        bool smallAns = isPresent(root->children[i], x);
        if (smallAns == true)
        {
            ans = smallAns;
        }
    }
    return ans;
}

// Nodes which contain data > x
int getLargeNodeCount(TreeNode<int> *root, int x)
{
    if (root == NULL)
    {
        return 0;
    }

    int count = 0;
    if (root->data > x)
    {
        count++;
    }

    for (int i = 0; i < root->children.size(); i++)
    {
        count += getLargeNodeCount(root->children[i], x);
    }
    return count;
}

// Node with maximum child sum
TreeNode<int> *maxSumNode(TreeNode<int> *root)
{
    TreeNode<int> *max = root;
    int maxSum = -1;
    queue<TreeNode<int> *> pendingNodes;
    pendingNodes.push(root);

    while (pendingNodes.size() != 0)
    {
        TreeNode<int> *front = pendingNodes.front();
        int sum = front->data;
        pendingNodes.pop();

        for (int i = 0; i < front->children.size(); i++)
        {
            sum += front->children[i]->data;
            pendingNodes.push(front->children[i]);
        }
        if (sum >= maxSum)
        {
            // cout << "In" << endl;
            maxSum = sum;
            max = front;
        }
    }
    // cout << "Out" << endl;
    return max;
}

// Next Larger
TreeNode<int> *getNextLargerElement(TreeNode<int> *root, int n)
{
    stack<TreeNode<int> *> s;
    queue<TreeNode<int> *> pendingNodes;

    if (root == NULL)
    {
        return NULL;
    }

    int flag = 0;

    pendingNodes.push(root);

    while (pendingNodes.size() != 0)
    {
        TreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        if (front->data > n)
        {
            flag = 1;
            if (s.empty())
            {
                s.push(front);
            }

            else
            {
                if (s.top()->data > front->data)
                {
                    s.pop();
                    s.push(front);
                }
            }
        }

        for (int i = 0; i < front->children.size(); i++)
        {
            pendingNodes.push(front->children[i]);
        }
    }
    if (flag == 1)
    {
        return s.top();
    }else{
        return NULL;
    }
}

void printTree(TreeNode<int> *root)
{
    if (root == NULL)
    {
        cout << "Tree is empty" << endl;
    }

    cout << "ROOT: " << root->data << endl
         << "ROOT CHILDREN: ";
    for (int i = 0; i < root->children.size(); i++)
    {
        cout << root->children[i]->data << " ";
    }
    cout << endl;

    for (int i = 0; i < root->children.size(); i++)
    {
        printTree(root->children[i]);
    }
}

int main()
{

    TreeNode<int> *root = takeInputLevelWise();
    /*
    TreeNode<int> *ans = maxDataNode(root);
    cout << "Total nodes are: " << totalNodes(root) << endl;
    cout << "Sum of nodes is: " << sumOfNodes(root) << endl;
    cout << "Node with maximum data: " << ans->data << endl;
    cout << "Total number of leaf Nodes are: " << getLeafNodeCount(root) << endl;

    cout << "Post order traversal: ";
    printPostOrder(root);
   */

    TreeNode<int> *m = maxSumNode(root);
    cout << "Node with max sum: " << m->data << endl;

    TreeNode<int> *n = getNextLargerElement(root, 15);
    cout << "Just larger element: " << n->data << endl;

    //  1 2 2 3 2 4 5 0 0 0
    /*
    int x;
    cout << endl
         << "Enter value to find" << endl;
    cin >> x;
    cout << "Present/Absent: " << isPresent(root, x);
    */

    /*
        int x;
        cout << endl << "Enter value x" << endl;
        cin >> x;
        cout << "Nodes > x are: " << getLargeNodeCount(root, x);
    */

    return 0;
}