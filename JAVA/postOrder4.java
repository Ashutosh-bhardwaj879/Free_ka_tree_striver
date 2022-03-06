class postOrder1 {
    public static void main(String[] args) {
        Node root = new Node(1);
        root.left = new Node(2);
        root.right = new Node(3);
        root.left.left = new Node(4);
        root.left.right = new Node(5);
        root.right.left = new Node(6);
        root.right.right = new Node(7);
        PostOrderTraversal(root);
    }

    public static void PostOrderTraversal(Node node) {
        if (node == null) {
            return;
        }
        PostOrderTraversal(node.left);
        PostOrderTraversal(node.right);
        System.out.print(node.data+" ");
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
