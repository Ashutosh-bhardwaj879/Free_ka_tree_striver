#include <bits/stdc++.h>
using namespace std;

struct Node
{
    Node *left;
    Node *right;
    int val;
    Node(int data)
    {
        val = data;
        left = nullptr;
        right = nullptr;
    }
};

void print(vector<int> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
}
vector<int> postOrder(Node *root)
{
    vector<int> v;
    if (root == NULL)
    {
        return v;
    }
    stack<Node *> st;
    Node *curr = root;

    while (curr != NULL || !st.empty())
    {
        if (curr != NULL)
        {
            st.push(curr);
            curr = curr->left;
        }
        else
        {
            Node *temp = st.top()->right;
            if (temp == NULL)
            {
                temp = st.top();
                st.pop();
                v.push_back(temp->val);

                while (!st.empty() && temp == st.top()->right)
                {
                    temp = st.top();
                    st.pop();
                    v.push_back(temp->val);
                }
            }
            else
            {
                curr = temp;
            }
        }
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
    vector<int> res = postOrder(root);
    print(res);
    return 0;
}