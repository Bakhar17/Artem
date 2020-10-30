package bsu;

public class Person implements Comparable<Person> {
    private int level;
    private String name;

    @Override
    public int compareTo(Person o) {
        if(level>o.level){
            return 5;
        }else if(level==o.level){
            return 0;
        }else return -3;
    }
}
