package by.bakhar.control;

public abstract class Learner implements Comparable<Learner> {
    private String name;
    private String nameOfUniversity;
    private double universityRate;
    private double mark;

    public Learner(String name, String nameOfUniversity, double universityRate, double mark) {
        this.name = name;
        this.nameOfUniversity = nameOfUniversity;
        this.universityRate = universityRate;
        this.mark = mark;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getNameOfUniversity() {
        return nameOfUniversity;
    }


    public double getMark() {
        return mark;
    }

    public void setMark(double mark) {
        this.mark = mark;
    }

    @Override
    public int compareTo(Learner o) {
        return -Double.compare(this.getMark(),o.getMark());
    }

    @Override
    public String toString() {
        return "name='" + name + '\'' +
                ", nameOfUniversity='" + nameOfUniversity + '\'' +
                ", universityRate=" + universityRate +
                ", mark=" + mark;
    }
}
