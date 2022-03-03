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

    st.push(root);

    while (st.empty() == false)
    {
        Node *temp = st.top();
        cout << temp->data << " ";
        st.pop();

        if (temp->right != NULL)
        {
            st.push(temp->right);
        }
        if (temp->left != NULL)
        {
            st.push(temp->left);
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