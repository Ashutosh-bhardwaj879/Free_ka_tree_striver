import java.util.*;

class inorder {
    public static void main(String[] args) {

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