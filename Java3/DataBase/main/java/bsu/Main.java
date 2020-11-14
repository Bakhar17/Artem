package bsu;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.*;

public class Main {
    public static void showInfoPanel() {
        System.out.println("1. Просмотреть всех людей\n" +
                "2. Отображение людей с данным именем\n" +
                "3. Отображение людей старше указанного возраста.\n" +
                "4. Отобразите человека с указанным идентификатором.\n" +
                "5. Отредактируйте человека с данным ID.\n" +
                "6. Удалите человека с данным ID.\n" +
                "7. Добавьте нового человека\n" +
                "8. Очистите список.\n" +
                "9. Сохраните лист в файл.\n" +
                "10. читать список из файла (сбросить)\n" +
                "11. Выйдите из программы.\n");
    }

    public static void main(String[] args) {
        DataBase base = new DataBase();
        File file = new File("text.txt");
        try {
            Reader.readBase(base, file);
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
        System.out.println(base);

        boolean flag = true;
        int k = 0;
        ArrayList<Man> temp;//вспомогательный
        Scanner scanner = new Scanner(System.in);
        while (flag) {
            showInfoPanel();
            try {
                System.out.print("Введите номер: ");
                k = Reader.readInt(scanner);
            } catch (InputMismatchException e) {
                System.out.println("Неправильно введенный номер");
            }
            switch (k) {
                case 1: {
                    System.out.println(base);
                    break;
                }
                case 2: {
                    System.out.print("Введите имя: ");
                    String name = Reader.readString(scanner);
                    temp = base.findByName(name);
                    if (temp.size() != 0) {
                        for (Man man : temp) {
                            System.out.println(man);
                        }
                    } else {
                        System.out.println("Человек с таким именем не найден!");
                    }
                    break;
                }
                case 3: {
                    System.out.println("Введите дату рождения через символ /\nДень/Месяц/Год");
                    try {
                        GregorianCalendar date = Reader.readDate(scanner);
                        temp = base.findOlderThan(date);
                        if (temp.size() != 0) {
                            for (Man man : temp) {
                                System.out.println(man);
                            }
                        } else {
                            System.out.println("Никого старше нет!");
                        }
                    } catch (NoSuchElementException e) {
                        System.out.println("Неправильно введена дата");
                    }


                    break;
                }
                case 4: {
                    System.out.print("Введите id: ");
                    try {
                        int n = Reader.readInt(scanner);
                        System.out.println(base.showAt(n));
                    } catch (InputMismatchException e) {
                        System.out.println("Неправильно введенный номер");
                    }
                    break;
                }
                case 5: {
                    System.out.print("Введите id: ");
                    try {
                        int n = Reader.readInt(scanner);
                        base.editMan(n);
                    } catch (InputMismatchException e) {
                        System.out.println("Неправильно введенный номер");
                    }
                    break;
                }
                case 6: {
                    System.out.print("Введите id: ");
                    try {
                        int n = Reader.readInt(scanner);
                        base.removeMan(n);
                    } catch (InputMismatchException e) {
                        System.out.println("Неправильно введенный номер");
                    }
                    break;
                }
                case 7: {
                    StringBuffer buffer=new StringBuffer();
                    buffer.append(base.size()).append(" ");
                    buffer.append(Reader.readManInfo(scanner));
                    try {
                        base.add(new Man(new String(buffer)));
                    }catch (NumberFormatException | NoSuchElementException e){
                        System.out.println("Данные введены неправильно. Человек не был добавлен");
                    }
                    break;
                }
                case 8: {
                    break;
                }
                case 9: {
                    try {
                        FileWriter fileWriter=new FileWriter(file,false);
                        for (int i = 0; i < base.size(); i++) {
                            fileWriter.write(base.showAt(i));
                        }
                        fileWriter.close();
                    }catch (IOException e){
                        System.out.println(e.getMessage());
                    }
                    break;
                }
                case 10: {
                    try {
                        Reader.readBase(base, file);
                    }catch (FileNotFoundException e){
                        System.out.println(e.getMessage());
                    }

                    break;
                }
                case 11: {
                    flag = false;

                }
                default:
                    System.out.println("No function");
                    break;
            }
        }
        scanner.close();
    }
}
