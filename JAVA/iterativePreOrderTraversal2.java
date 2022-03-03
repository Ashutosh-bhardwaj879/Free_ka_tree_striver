import java.util.Stack;

class iterativePreOrderTraversal2 {
    public static void main(String[] args) {
        Node root = new Node(1);
        root.left = new Node(2);
        root.right = new Node(3);
        root.left.left = new Node(4);
        root.left.right = new Node(5);
        root.right.left = new Node(6);
        root.right.right = new Node(7);
        preOrderTreversal(root);
    }

    public static void preOrderTreversal(Node root) {
        if (root == null) {
            return;
        }
        Stack<Node> st = new Stack<Node>();

        Node curr = root;

        while (curr != null || !st.isEmpty()) {

            while (curr != null) {
                System.out.print(curr.data + " ");

                if (curr.right != null) {
                    st.push(curr.right);
                }

                curr = curr.left;

            }

            if (!st.isEmpty()) {
                curr = st.pop();
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
