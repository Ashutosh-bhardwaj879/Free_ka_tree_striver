import java.util.*;

class postOrder1stack {
    public static void main(String[] args) {
        Node root = new Node(1);
        root.left = new Node(2);
        root.right = new Node(3);
        root.left.left = new Node(4);
        root.left.right = new Node(5);
        root.right.left = new Node(6);
        root.right.right = new Node(7);
        List<Integer> res = postOrder(root);
        print(res);
    }

    public static void print(List<Integer> res) {
        System.out.println(res);
    }

    public static List<Integer> postOrder(Node root){
        List<Integer> res = new ArrayList<Integer>();
        Stack<Node> st = new Stack<Node>();
        if(root == null){
            return res;
        }
        Node curr = root;

        while(!st.isEmpty() || curr !=null){
            if(curr!=null){
                st.push(curr);
                curr=curr.left;
            }else{
                Node temp = st.peek().right;
                if(temp==null){
                    temp = st.peek();
                    st.pop();
                    res.add(temp.data);
                    while(!st.isEmpty() && st.peek().right==temp){
                        temp=st.peek();
                        st.pop();
                        res.add(temp.data);
                    }
                }else{
                    curr=temp;
                }
            }
        }
        return res;
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
