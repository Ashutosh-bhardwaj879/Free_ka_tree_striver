import java.util.*;

class postOrder {
    public static void main(String[] args) {
        Node root = new Node(1);
        root.left = new Node(2);
        root.right = new Node(3);
        root.left.left = new Node(4);
        root.left.right = new Node(5);
        root.right.left = new Node(6);
        root.right.right = new Node(7);
        List<Integer> res = postOrder2Stack(root);
        print(res);
    }

    public static void print(List<Integer> res) {
        System.out.println(res);
    }

    public static List<Integer> postOrder2Stack(Node root) {
        List<Integer> list = new ArrayList<Integer>();
        Stack<Node> st1 = new Stack<Node>();
        Stack<Node> st2 = new Stack<Node>();

        if (root == null) {
            return list;
        }

        st1.push(root);

        while (!st1.isEmpty()) {

            root = st1.pop();
            st2.add(root);

            if (root.left != null) {
                st1.push(root.left);
            }

            if (root.right != null) {
                st1.push(root.right);
            }

        }

        while (!st2.isEmpty()) {
            list.add(st2.pop().val);
        }
        return list;
    }

    public static class Node {
        Node left;
        Node right;
        int val;

        public Node(int val) {
            this.val = val;
        }
    }
}
