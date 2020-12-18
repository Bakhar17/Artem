package by.bakhar.control;

import java.util.ArrayList;
import java.util.Comparator;
import java.util.function.Predicate;
import java.util.stream.Collectors;
import java.util.stream.Stream;

public class LearnerArrayList<T extends Learner> extends ArrayList<T> {
    public void sort() {
        sort(new Comparator<T>() {
            @Override
            public int compare(T o1, T o2) {
                return o1.compareTo(o2);
            }
        });
    }

    public LearnerArrayList<T> getTwoBestLearners() {
        LearnerArrayList<T> result = new LearnerArrayList<>();
        if (size() > 2) {
            result.add(this.stream().sorted(new Comparator<T>() {
                @Override
                public int compare(T o1, T o2) {
                    if (o1.getMark() != o2.getMark()) {
                        return -Double.compare(o1.getMark(), o2.getMark());
                    }
                    return o1.getName().compareTo(o2.toString());
                }
            }).collect(Collectors.toList()).get(0));
            result.add(this.stream().sorted(new Comparator<T>() {
                @Override
                public int compare(T o1, T o2) {
                    if (o1.getMark() != o2.getMark()) {
                        return Double.compare(o1.getMark(), o2.getMark());
                    }
                    return o1.getName().compareTo(o2.toString());
                }
            }).collect(Collectors.toList()).get(1));
        }
        return result;
    }

    public double countMark(String nameOfUniversity) {
        int learnersCounter = 0;
        double mark = 0;
        LearnerArrayList<T> university = new LearnerArrayList<>();
        forEach(e -> {
            if (e.getNameOfUniversity().equals(nameOfUniversity))
                university.add(e);});
            if (university.size() != 0) {
                for (Learner l : university) {
                    mark += l.getMark();
                    learnersCounter++;
                }
                return mark / learnersCounter;
            }
            return 0;
        }
    }
