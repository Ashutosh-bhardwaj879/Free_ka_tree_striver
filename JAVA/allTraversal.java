import java.util.*;

class allTraversal {
    public static void main(String[] args) {
        Node root = new Node(1);
        root.left = new Node(2);
        root.right = new Node(3);
        root.left.left = new Node(4);
        root.left.right = new Node(5);
        root.right.left = new Node(6);
        root.right.right = new Node(7);
        Traversal(root);
    }

    public static class Node {
        Node left;
        Node right;
        int data;

        public Node(int data) {
            this.data = data;
        }
    }

    public static class pair {
        Node first;
        int second;

        public pair(Node first, int second) {
            this.first = first;
            this.second = second;
        }
    }

    public static void Traversal(Node root) {
        Stack<pair> st = new Stack<pair>();
        ArrayList<Integer> pre = new ArrayList<Integer>();
        ArrayList<Integer> post = new ArrayList<Integer>();
        ArrayList<Integer> in = new ArrayList<Integer>();
        if (root == null) {
            return;
        }

        st.push(new pair(root, 1));

        while (!st.isEmpty()) {
            pair p = st.peek();

            if (p.second == 1) {
                st.peek().second++;
                pre.add(p.first.data);

                if (p.first.left != null) {
                    st.push(new pair(p.first.left, 1));
                }
            } else if (p.second == 2) {
                st.peek().second++;
                in.add(p.first.data);

                if (p.first.right != null) {
                    st.push(new pair(p.first.right, 1));
                }
            } else if (p.second == 3) {
                post.add(p.first.data);
                st.pop();
            }
        }

        System.out.print("Preorder Traversal: ");
        for (int i : pre) {
            System.out.print(i + " ");
        }
        System.out.println();

        // Printing Inorder
        System.out.print("Inorder Traversal: ");
        for (int i : in) {
            System.out.print(i + " ");
        }
        System.out.println();

        // Printing Postorder
        System.out.print("Postorder Traversal: ");
        for (int i : post) {
            System.out.print(i + " ");
        }
        System.out.println();
    }
}
