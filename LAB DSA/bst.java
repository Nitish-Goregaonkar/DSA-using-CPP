import java.util.Scanner;

class Node {
    int data;
    Node left, right;

    Node(int value) {
        data = value;
        left = right = null;
    }
}

class TreeTraversal {

    static Scanner sc = new Scanner(System.in);

    
    public static Node createTree() {
        System.out.print("Enter value : ");
        int val = sc.nextInt();

        if (val == -1) {
            return null;
        }

        Node root = new Node(val);

        System.out.println("Enter left of " + val);
        root.left = createTree();

        System.out.println("Enter right of " + val);
        root.right = createTree();

        return root;
    }

   
    public static void inorder(Node root) {
        if (root != null) {
            inorder(root.left);
            System.out.print(root.data + " ");
            inorder(root.right);
        }
    }

  
    public static void preorder(Node root) {
        if (root != null) {
            System.out.print(root.data + " ");
            preorder(root.left);
            preorder(root.right);
        }
    }

   
    public static void postorder(Node root) {
        if (root != null) {
            postorder(root.left);
            postorder(root.right);
            System.out.print(root.data + " ");
        }
    }

    public static void main(String[] args) {

        Node root = createTree();

        System.out.print("Inorder: ");
        inorder(root);

        System.out.print("\nPreorder: ");
        preorder(root);

        System.out.print("\nPostorder: ");
        postorder(root);
    }
}