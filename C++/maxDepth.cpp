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
        right = left = NULL;
    }
};
int Height(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int leftHeight = Height(root->left);
    int rightHeight = Height(root->right);
    return 1 + max(leftHeight, rightHeight);
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
    root->right->right->left = new Node(7);
    cout << Height(root);
    return 0;
}