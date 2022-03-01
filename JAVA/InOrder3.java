class InOrder {
    public static void main(String[] args) {
        Node root = new Node(1);
        root.left = new Node(2);
        root.right = new Node(3);
        root.left.left = new Node(4);
        root.left.right = new Node(5);
        root.right.left = new Node(6);
        root.right.right = new Node(7);
        inOrderTraversal(root);
    }

    public static void inOrderTraversal(Node node) {
        if (node == null) {
            return;
        }
        inOrderTraversal(node.left);
        System.out.print(node.data+" ");
        inOrderTraversal(node.right);
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