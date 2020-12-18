package by.bakhar.control;

public class SchoolBoy  extends Learner{
    private int form;
    private Behavior behavior;

    public SchoolBoy(String name, String nameOfUniversity, double universityRate, double mark, int form, Behavior behavior) {
        super(name, nameOfUniversity, universityRate, mark);
        this.form = form;
        this.behavior = behavior;
    }

    @Override
    public String toString() {
        return super.toString()+" form="+form+" behavior="+behavior;
    }
}
