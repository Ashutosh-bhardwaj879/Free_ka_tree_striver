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
vector<int> inOrderTraversal(Node *root)
{
    vector<int> inOrder;
    if (root == NULL)
    {
        return inOrder;
    }
    stack<Node *> st;
    Node *node = root;
    while (true)
    {
        if (node != NULL)
        {
            st.push(node);
            node = node->left;
        }
        else
        {
            if (st.empty() == true)
            {
                break;
            }
            node = st.top();
            st.pop();
            inOrder.push_back(node->data);
            node = node->right;
        }
    }
    return inOrder;
}
void print(vector<int> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
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
    vector<int> result = inOrderTraversal(root);
    print(result);
    return 0;
}