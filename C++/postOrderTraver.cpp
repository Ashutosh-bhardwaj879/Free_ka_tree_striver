#include <bits/stdc++.h>
using namespace std;

struct Node
{
    Node *left;
    Node *right;
    int val;
    Node(int data)
    {
        left = nullptr;
        right = nullptr;
        val = data;
    }
};
void print(vector<int> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
}
vector<int> postOrder2stack(Node *root)
{
    vector<int> v;
    stack<Node *> st1;
    stack<Node *> st2;
    if (root == NULL)
    {
        return v;
    }
    st1.push(root);

    while (!st1.empty())
    {
        root = st1.top();
        st1.pop();
        st2.push(root);
        if (root->left != NULL)
        {
            st1.push(root->left);
        }
        if (root->right != NULL)
        {
            st1.push(root->right);
        }
    }
    while (!st2.empty())
    {
        v.push_back(st2.top()->val);
        st2.pop();
    }
    return v;
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
    vector<int> result = postOrder2stack(root);
    print(result);
    return 0;
}