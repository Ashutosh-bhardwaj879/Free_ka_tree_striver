class balancedBinaryTree {
    public static void main(String[] args) {
        Node root = new Node(1);
        root.left = new Node(2);
        root.right = new Node(3);
        root.left.left = new Node(4);
        root.left.right = new Node(5);
        root.right.left = new Node(6);
        root.right.right = new Node(7);
        boolean res = isBalanced(root);
        if (res == true) {
            System.out.println("TREE IS BALANCED");
        } else {
            System.out.println("TREE IS NOT BALANCED");
        }
    }

    public static boolean isBalanced(Node root) {
        return dfsHeight(root) != -1;
    }

    public static int dfsHeight(Node root) {
        if (root == null) {
            return 0;
        }
        int lh = dfsHeight(root.left);
        if (lh == -1) {
            return -1;
        }
        int rh = dfsHeight(root.right);
        if (rh == -1) {
            return -1;
        }
        if (Math.abs(lh - rh) > 1) {
            return -1;
        }
        return Math.max(lh, rh) + 1;
    }

    public static class Node {
        Node left;
        Node right;
        int data;

        public Node(int data) {
            this.data = data;
        }
    }
}
