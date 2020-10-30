package bsu;

public class Tree<T extends Comparable<T>> {
    private Node root;

    public Tree() {
        root = null;
    }

    public boolean binaryFind(T data) {
        return binaryFind(root, data);
    }

    private class Node {
        private Node parent;
        private Node left;
        private Node right;
        private final T data;

        public Node(Node par, Node l, Node r, T data) {
            parent = par;
            left = l;
            right = r;
            this.data = data;
        }

    }

    private Node binaryInsert(Node node, T data) {
        int n = node.data.compareTo(data);
        if (n < 0) {
            if (node.right == null) {
                return node.right = new Node(node, null, null, data);
            }
            return binaryInsert(node.right, data);
        } else if (n == 0) return node;
        else {
            if (node.left == null) {
                return node.left = new Node(node, null, null, data);
            }
            return binaryInsert(node.left, data);
        }
    }

    public void add(T data) {
        if (root == null) {
            root = new Node(null, null, null, data);
        } else {
            binaryInsert(root, data);
        }
    }

    private boolean binaryFind(Node node, T data) {
        int n = node.data.compareTo(data);
        if (n < 0) {
            if (node.right == null) {
                return false;
            }
            return binaryFind(node.right, data);
        } else if (n > 0) {
            if (node.left == null) {
                return false;
            }
            return binaryFind(node.left, data);
        } else {
            return true;
        }
    }

    private void passLeftRightRoot(Node node) {
        if (node != null) {
            passLeftRightRoot(node.left);
            passLeftRightRoot(node.right);
            System.out.print(node.data + " ");
        }
    }

    public void passLeftRightRoot() {
        passLeftRightRoot(root);
        System.out.println();
    }

    private void passLeftRootRight(Node node) {
        if (node != null) {
            passLeftRootRight(node.left);
            System.out.print(node.data + " ");
            passLeftRootRight(node.right);
        }
    }

    public void passLeftRootRight() {
        passLeftRootRight(root);
        System.out.println();
    }

    private void passRootLeftRight(Node node) {
        if (node != null) {
            System.out.print(node.data + " ");
            passRootLeftRight(node.left);
            passRootLeftRight(node.right);
        }
    }
    public void passRootLeftRight(){
        passRootLeftRight(root);
        System.out.println();
    }

}
