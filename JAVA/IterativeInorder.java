import java.util.*;

class ItertiveInorder {
    public static void main(String[] args) {
        Node root = new Node(1);
        root.left = new Node(2);
        root.right = new Node(3);
        root.left.left = new Node(4);
        root.left.right = new Node(5);
        root.right.left = new Node(6);
        root.right.right = new Node(7);
        List<Integer> res = inOrderTraversal(root);
        print(res);
    }

    public static void print(List<Integer> res) {
        System.out.println(res);
    }

    public static List<Integer> inOrderTraversal(Node root) {
        List<Integer> inorder = new ArrayList<Integer>();

        if (root == null) {
            return inorder;
        }
        Stack<Node> st = new Stack<Node>();
        Node node = root;

        while (true) {
            if (node != null) {
                st.push(node);
                node = node.left;
            } else {
                if (st.isEmpty() == true) {
                    break;
                }
                node = st.pop();
                inorder.add(node.data);
                node = node.right;
            }
        }
        return inorder;
    }

    public static class Node {
        Node left;
        Node right;
        int data;

        public Node(int val) {
            data = val;
        }
    }

}