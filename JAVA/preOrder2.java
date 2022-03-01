class preOrderTraversal {
    public static void main(String[] args) {
        Node root = new Node(1);
        root.left = new Node(2);
        root.right = new Node(3);
        root.left.left = new Node(4);
        root.left.right = new Node(5);
        root.right.left = new Node(6);
        root.right.right = new Node(7);
        preOrder(root);
    }

    public static class Node {
        int data;
        Node left;
        Node right;

        Node(int value) {
            data = value;
        }
    }

    public static void preOrder(Node node) {
        if (node == null) {
            return;
        }
        System.out.print(node.data+" ");
        preOrder(node.left);
        preOrder(node.right);
    }
}
