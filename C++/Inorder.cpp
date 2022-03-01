#include <bits/stdc++.h>
using namespace std;

struct Node
{
    struct Node *left;
    struct Node *right;
    int data;
    Node(int value)
    {
        data = value;
        left = NULL;
        right = NULL;
    }
};

void inorder(struct Node *node)
{
    if (node == NULL)
    {
        return;
    }
    inorder(node->left);
    cout << node->data << " ";
    inorder(node->right);
}
int main()
{
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    inorder(root);
}