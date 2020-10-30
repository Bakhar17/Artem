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
        Tree<Person> personTree = new Tree<>();
        personTree.add(new Person(5,"Artem"));
        personTree.add(new Person(2,"Vanya"));
        personTree.add(new Person(6,"Gosha"));
        personTree.add(new Person(0,"Petra"));
        personTree.add(new Person(25,"Dima"));
        System.out.println(personTree.binaryFind(new Person(2,"Artem")));
        personTree.passRootLeftRight();
        personTree.passLeftRootRight();
        personTree.passLeftRightRoot();
    }
}
