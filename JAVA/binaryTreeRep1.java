import java.util.*;



class Main {
    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);
        Node root = new Node(1);
        root.left = new Node(2);
        root.right = new Node(3);
        root.left.right = new Node(4);
        printTree(root);
        scn.close();
    }

    public static void printTree(Node node) {
        if (node == null) {
            return;
        }
        System.out.println(node.data);
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