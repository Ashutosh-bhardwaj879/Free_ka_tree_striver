// C++ program for the above approach

#include <bits/stdc++.h>
using namespace std;

// Structure of the
// node of a binary tree
struct Node
{
    int data;
    struct Node *left, *right;

    Node(int data)
    {
        this->data = data;
        left = right = NULL;
    }
};

// Function to print all nodes of a
// binary tree in Preorder, Postorder
// and Inorder using only one stack
void allTraversal(Node *root)
{
    // Stores preorder traversal
    vector<int> pre;

    // Stores inorder traversal
    vector<int> post;

    // Stores postorder traversal
    vector<int> in;

    // Stores the nodes and the order
    // in which they are currently visited
    stack<pair<Node *, int>> s;

    // Push root node of the tree
    // into the stack
    s.push(make_pair(root, 1));

    // Traverse the stack while
    // the stack is not empty
    while (!s.empty())
    {

        // Stores the top
        // element of the stack
        pair<Node *, int> p = s.top();

        // If the status of top node
        // of the stack is 1
        if (p.second == 1)
        {

            // Update the status
            // of top node
            s.top().second++;

            // Insert the current node
            // into preorder, pre[]
            pre.push_back(p.first->data);

            // If left child is not NULL
            if (p.first->left)
            {

                // Insert the left subtree
                // with status code 1
                s.push(make_pair(
                    p.first->left, 1));
            }
        }

        // If the status of top node
        // of the stack is 2
        else if (p.second == 2)
        {

            // Update the status
            // of top node
            s.top().second++;

            // Insert the current node
            // in inorder, in[]
            in.push_back(p.first->data);

            // If right child is not NULL
            if (p.first->right)
            {

                // Insert the right subtree into
                // the stack with status code 1
                s.push(make_pair(
                    p.first->right, 1));
            }
        }

        // If the status of top node
        // of the stack is 3
        else
        {

            // Push the current node
            // in post[]
            post.push_back(p.first->data);

            // Pop the top node
            s.pop();
        }
    }

    cout << "Preorder Traversal: ";
    for (int i = 0; i < pre.size(); i++)
    {
        cout << pre[i] << " ";
    }
    cout << "\n";

    // Printing Inorder
    cout << "Inorder Traversal: ";

    for (int i = 0; i < in.size(); i++)
    {
        cout << in[i] << " ";
    }
    cout << "\n";

    // Printing Postorder
    cout << "Postorder Traversal: ";

    for (int i = 0; i < post.size(); i++)
    {
        cout << post[i] << " ";
    }
    cout << "\n";
}

// Driver Code
int main()
{

    // Creating the root
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    // Function call
    allTraversal(root);

    return 0;
}
