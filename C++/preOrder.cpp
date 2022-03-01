#include <bits/stdc++.h>
using namespace std;

struct Node
{
    Node *left;
    Node *right;
    int data;
    Node(int value)
    {
        data = value;
        left = NULL;
        right = NULL;
    }
};
void preOrder(struct Node *node)
{
    if (node == NULL)
    {
        return;
    }
    cout << node->data << " ";
    preOrder(node->left);
    preOrder(node->right);
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
    preOrder(root);
}