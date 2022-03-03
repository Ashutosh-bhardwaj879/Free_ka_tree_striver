#include <bits/stdc++.h>
using namespace std;

struct Node
{
    struct Node *left;
    struct Node *right;
    int data;

    Node(int val)
    {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

void iterativePreOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    stack<Node *> st;

    Node *curr = root;

    while (curr != NULL || st.empty() == false)
    {
        while (curr != NULL)
        {
            cout << curr->data << " ";
            if (curr->right != NULL)
            {
                st.push(curr->right);
            }
            curr = curr->left;
        }

        if (st.empty() == false)
        {
            curr = st.top();
            st.pop();
        }
    }
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
    iterativePreOrder(root);
    return 0;
}