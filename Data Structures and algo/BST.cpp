#include <climits>
#include <cmath>
#include <queue>
#include "BinaryTreeNode.h"
#include <iostream>
using namespace std;

BinaryTreeNode<int> *takeInput()
{
    int rootData;
    cin >> rootData;
    if (rootData == -1)
    {
        return NULL; 
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    while (!q.empty())
    {
        BinaryTreeNode<int> *currentNode = q.front();
        q.pop();
        int leftChild, rightChild;

        cin >> leftChild;
        if (leftChild != -1)
        {
            BinaryTreeNode<int> *leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode->left = leftNode;
            q.push(leftNode);
        }

        cin >> rightChild;
        if (rightChild != -1)
        {
            BinaryTreeNode<int> *rightNode =
                new BinaryTreeNode<int>(rightChild);
            currentNode->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

int minimum(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return INT_MAX;
    }

    return min(root->data, min(minimum(root->left), minimum(root->right)));
}

int maximum(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return INT_MIN;
    }

    return max(root->data, max(maximum(root->left), maximum(root->right)));
}

bool isBST(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return true;
    }

    int LeftMax = maximum(root->left);
    int RightMin = minimum(root->right);

    bool output = (root->data > LeftMax) && (root->data <= RightMin) && (isBST(root->left)) && (isBST(root->right));
    return output;
}

//Time Complexity of this will be O(n)
class IsBSTReturn
{
public:
    bool isBST;
    int minimum;
    int maximum;
};

IsBSTReturn isBST2(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        IsBSTReturn output;
        output.isBST = true;
        output.minimum = INT_MAX;
        output.maximum = INT_MIN;
    }

    IsBSTReturn leftOutput = isBST2(root->left);
    IsBSTReturn rightOutput = isBST2(root->right);
    int minimum = min(root->data, min(leftOutput.minimum, rightOutput.minimum));
    int maximum = max(root->data, max(leftOutput.maximum, rightOutput.maximum));
    bool isBSTFinal = (root->data > leftOutput.maximum) && (root->data <= rightOutput.minimum) && (leftOutput.isBST) && (rightOutput.isBST);

    IsBSTReturn output;
    output.minimum = minimum;
    output.maximum = maximum;
    output.isBST = isBSTFinal;
    return output;
}

vector<int>* getRootToNodePath(BinaryTreeNode<int>* root, int data){
  if(root == NULL){
    return NULL;
  }

  if(root -> data == data){
    vector<int> *output = new vector<int>();
    output -> push_back(root -> data);
    return output;
  }

  vector<int>* leftOutput = getRootToNodePath(root -> left, data);
  if(leftOutput != NULL){
     leftOutput->push_back(root -> data);
     return leftOutput;
  }

  vector<int>* rightOutput = getRootToNodePath(root -> right, data);
  if(rightOutput != NULL){
    rightOutput -> push_back(root -> data);
    return rightOutput;
  }
  else 
    return NULL;

}

bool isBST3(BinaryTreeNode<int>* root, int min = INT_MIN, int max = INT_MAX){
    if(root == NULL){
       return true;
    }

    if(root -> data < min || root -> data > max){
        return false;
    }

    bool isLeftOk = isBST3(root -> left, min, root -> data - 1);
    bool isRightOk = isBST3(root -> right, root -> data, max);

    return isLeftOk && isRightOk;
}

/* Very Very IMPORTANT!(part of BST class problem)
BinaryTreeNode<int>* deleteData(int data, BinaryTreeNode<int>* node){
    if(node == NULL){
        return NULL;
    }

    if(data > node -> data){
        node -> right = deleteData(data, node -> right);
        return node;
    }
    else if(data < node -> data){
        node -> left = deleteData(data, node -> left);
        return node;
    }
    else{
        if(node -> left == NULL && node -> right == NULL){
            delete node;
            return NULL;
        }
        else if(node -> left == NULL){
            BinaryTreeNode<int>* temp = node -> right;
            node -> right = NULL;
            delete node;
            return temp;    
        }
        else if(node -> right == NULL){
            BinaryTreeNode<int>* temp = node -> left;
            node -> left = NULL;
            delete node;
            return temp;
        }
        else{
            BinaryTreeNode<int>* minNode = node -> right;
            while(minNode -> left != NULL){
                minNode = minNode -> left;
            }
            int rightMin = minNode -> data;
            node -> data = rightMin;
            node -> right = deleteData(rightMin, node -> right);
            return node;
        }
    }
}
*/

int main()
{
    BinaryTreeNode<int> *root = takeInput();
    // cout << (isBST(root) ? "true" : "false");
    // cout << isBST(root) << endl;

    int data;
    cout << "Please enter the data" << endl;
    cin >> data;

    vector<int>* output = getRootToNodePath(root, data);
    for(int i = 0; i < output -> size(); i++){
        cout << output -> at(i) << endl;
    }

    delete output;
    // delete root;
}