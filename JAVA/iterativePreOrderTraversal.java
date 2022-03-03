import java.util.*;

class iterativePreTrversal {
    public static void main(String[] args) {
        Node root = new Node(1);
        root.left = new Node(2);
        root.right = new Node(3);
        root.left.left = new Node(4);
        root.left.right = new Node(5);
        root.right.left = new Node(6);
        root.right.right = new Node(7);
        preOrderIterative(root);
    }

    public static void preOrderIterative(Node root) {
        if (root == null) {
            return;
        }
        Stack<Node> st = new Stack<Node>();
        st.push(root);
        while (st.empty() == false) {
            Node temp = st.peek();
            System.out.print(temp.data + " ");
            st.pop();

            if (temp.right != null) {
                st.push(temp.right);
            }
            if (temp.left != null) {
                st.push(temp.left);
            }
        }
    }

    public static class Node {
        Node left;
        Node right;
        int data;

        public Node(int value) {
            data = value;
        }
    }
}