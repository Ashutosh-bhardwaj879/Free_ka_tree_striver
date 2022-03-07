#include <bits/stdc++.h>
using namespace std;

struct Node
{
    Node *left;
    Node *right;
    int data;
    Node(int val)
    {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
int dfsHeight(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int lh = dfsHeight(root->left);
    if (lh == -1)
    {
        return -1;
    }
    int rh = dfsHeight(root->right);
    if (rh == -1)
    {
        return -1;
    }
    if (abs(lh - rh) > 1)
    {
        return -1;
    }
    return (1 + max(lh, rh));
}
bool isBalanced(Node *root)
{
    return dfsHeight(root) != -1;
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    bool res = isBalanced(root);
    if (res == true)
    {
        cout << "Binary Tree is Balanced" << endl;
    }
    else
    {
        cout << "Binary tree not balanced" << endl;
    }
    return 0;
}