#include <bits/stdc++.h>
using namespace std;

struct Node
{
    struct Node *right;
    struct Node *left;
    int data;
    Node(int value)
    {
        data = value;
        left = NULL;
        right = NULL;
    }
};
void PostOrderTraversal(struct Node *node)
{
    if (node == NULL)
    {
        return;
    }
    PostOrderTraversal(node->left);
    PostOrderTraversal(node->right);
    cout << node->data << " ";
}
int main()
{
    //struct Node *root = new Node(1);
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    PostOrderTraversal(root);
    return 0;
}