package bsu;

public class Main {
    public static void main(String[] args) {
        Tree<Integer> tree = new Tree<>();
        tree.add(42);
        tree.add(65);
        tree.add(13);
        tree.add(-5);
        tree.add(6);
        tree.add(1);
        tree.add(152);
        tree.add(23);
        tree.add(75);
        System.out.println(tree.binaryFind(13));
        System.out.println(tree.binaryFind(1));
        System.out.println(tree.binaryFind(0));
        tree.passLeftRightRoot();
        tree.passLeftRootRight();
        tree.passRootLeftRight();
    }
}
