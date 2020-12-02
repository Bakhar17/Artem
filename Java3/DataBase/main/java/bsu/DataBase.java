package bsu;

import java.util.*;

public class DataBase {
    private ArrayList<Man> base = new ArrayList<>();

    public void add(Man man) {
        this.base.add(man);
    }

    public int size() {
        return base.size();
    }

    public void removeAll() {
        base.clear();
    }

    @Override
    public String toString() {
        StringBuffer result = new StringBuffer();
        for (Man man : base) {
            result.append(man);
        }
        return new String(result);
    }

    public ArrayList<Man> findByName(String name) {
        ArrayList<Man> baseByName = new ArrayList<>();
        for (Man man : base) {
            if (man.equalsName(name)) {
                baseByName.add(man);
            }
        }
        return baseByName;
    }

    private boolean existsId(int k) {
        for (Man man : base) {
            if (man.getId() == k) {
                return true;
            }
        }
        return false;
    }

    public String showAt(int id) {
        if (this.existsId(id)) {
            return base.get(id).toString();
        }
        return "С таким id человек не найден!";
    }

    public Man get(int k) {
        return base.get(k);
    }

    public ArrayList<Man> findOlderThan(Calendar date) {
        ArrayList<Man> baseByDate = new ArrayList<>();
        for (Man man : base) {
            if (man.getBirthday().before(date)) {
                baseByDate.add(man);
            }
        }
        return baseByDate;
    }

    public void removeMan(int id) {
        if (existsId(id)) {
            base.remove(id);
        }
    }

    public void editMan(int id) {
        if (this.existsId(id)) {
            Man man = base.get(id);
            Man.showEditPanel();
            Scanner scanner = new Scanner(System.in);
            int n = Reader.readInt(scanner);
            switch (n) {
                case 1: {
                    System.out.println("Введите новое имя: ");
                    man.setName(Reader.readString(scanner));
                    break;
                }
                case 2: {
                    System.out.println("Введите новою фамилию: ");
                    man.setSurname(Reader.readString(scanner));
                    break;
                }
                case 3: {
                    System.out.println("Введите новую дату рождения через символ /\nДень/Месяц/Год");
                    try {
                        man.setBirthday(Reader.readDate(scanner));
                    } catch (NoSuchElementException e) {
                        System.out.println("Неправильна введена дата. Дата рождения не была изменена");
                    }
                    break;
                }
                case 4: {
                    System.out.println("Введите пол(M/F): ");
                    String sex = Reader.readString(scanner);
                    if (sex.equals("M")) {
                        man.setSex(0);
                    } else if (sex.equals("F")) {
                        man.setSex(1);
                    } else {
                        System.out.println("Неправильно введен пол. Пол не был изменен.");
                    }
                    break;
                }
                case 5: {
                    System.out.println("Введите образование: ");
                    man.setEducation(Reader.readString(scanner));
                    break;
                }
                case 6: {
                    System.out.println("Введите женат/замужем(Y/N): ");
                    String married = Reader.readString(scanner);
                    if (married.equals("Y")) {
                        man.setMarried(true);
                    } else if (married.equals("N")) {
                        man.setMarried(false);
                    } else {
                        System.out.println("Пол не был изменен");
                    }
                    break;
                }
                case 7: {
                    System.out.println("Введите количество детей: ");
                    try {
                        int children = Reader.readInt(scanner);
                        if (children < 0)
                            throw new NumberFormatException("Количество детей не может быть меньше нуля. Количество детей не изменено");
                    } catch (NumberFormatException e) {
                        System.out.println(e.getMessage());
                    } catch (InputMismatchException e) {
                        System.out.println("Неверно введено количество. Количество детей не изменено");
                    }
                    break;
                }
                case 8: {
                    System.out.println("Введите судим ли(Y/N): ");
                    String judged = Reader.readString(scanner);
                    if (judged.equals("Y")) {
                        man.setJudged(true);
                    } else if (judged.equals("N")) {
                        man.setJudged(false);
                    } else {
                        System.out.println("Судимость не была изменена");
                    }
                    break;
                }
                case 9: {
                    System.out.println("Введите место работы(если нет работы null): ");
                    String job = Reader.readString(scanner);
                    if (job.equals("null")) {
                        man.setJob("null");
                        man.setSalary(0);
                        man.setDataOfGettingJob(null);
                    } else {
                        try {
                            System.out.println("Введите зарплату: ");
                            double salary = Reader.readDouble(scanner);
                            System.out.println("Введите дату получения работы через символ /\nДень/Месяц/Год");
                            Calendar date = Reader.readDate(scanner);
                            man.setJob(job);
                            man.setSalary(salary);
                            man.setDataOfGettingJob(date);
                        } catch (NoSuchElementException e) {
                            System.out.println("Неправильно введены данные. Информация не была изменена");
                        }
                    }
                    break;
                }
                default:
                    break;
            }
        }
    }
}
