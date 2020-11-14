package bsu;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.*;

public class Reader {
    public static void readBase(DataBase base, File file) throws FileNotFoundException {
        Scanner scanner=new Scanner(file);
        String temp;
        while(scanner.hasNext()){
            temp=scanner.nextLine();
            try {
                base.add(new Man(temp));
            }catch (NumberFormatException e){
                System.out.println("Wrong file!\nFile has problems. Someone couldn't be read");
            }

        }
        scanner.close();
    }
    public static int readInt(Scanner scanner)throws InputMismatchException {
        return scanner.nextInt();
    }
    public static String readString(Scanner scanner){
        return scanner.next();
    }
    public static GregorianCalendar readDate(Scanner scanner)throws NoSuchElementException{
        GregorianCalendar date=new GregorianCalendar();
        StringTokenizer token=new StringTokenizer(readString(scanner),"/",false);
        date.set(Calendar.DATE,Integer.parseInt(token.nextToken()));
        date.set(Calendar.MONTH,Integer.parseInt(token.nextToken()));
        date.set(Calendar.YEAR,Integer.parseInt(token.nextToken()));
        return date;
    }
    public static double readDouble(Scanner scanner)throws InputMismatchException{
        return scanner.nextDouble();
    }
    public static String readManInfo(Scanner scanner){
        StringBuffer buffer=new StringBuffer();
        System.out.println("Введите имя: ");
        buffer.append(Reader.readString(scanner)).append(" ");
        System.out.println("Введите Фамилию: ");
        buffer.append(Reader.readString(scanner)).append(" ");
        System.out.println("Введите дату рождения(День/Месяц/Год): ");
        buffer.append(Reader.readString(scanner)).append(" ");
        System.out.println("Введите пол(M/F): ");
        buffer.append(Reader.readString(scanner)).append(" ");
        System.out.println("Образование: ");
        buffer.append(Reader.readString(scanner)).append(" ");
        System.out.println("Женат/Замужем(Y/N): ");
        buffer.append(Reader.readString(scanner)).append(" ");
        System.out.println("Введите количество детей: ");
        buffer.append(Reader.readString(scanner)).append(" ");
        System.out.println("Введите судимость(Y/N): ");
        buffer.append(Reader.readString(scanner)).append(" ");
        System.out.println("Место работы: ");
        String job=Reader.readString(scanner);
        if(job.equals("null")){
            buffer.append(job);
        }else{
            buffer.append(job).append(" ");
            System.out.println("Зарплата: ");
            buffer.append(Reader.readString(scanner)).append(" ");
            System.out.println("Введите дату приема на работу(День/Месяц/Год): ");
            buffer.append(Reader.readString(scanner));
        }
        return new String(buffer);
    }
}
