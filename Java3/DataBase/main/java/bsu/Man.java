package bsu;

import java.util.*;

public class Man {
    private int id;
    private String name;
    private String surname;
    private Calendar birthday;
    private int sex;
    private String education;
    private boolean married = false;
    private int children;
    private boolean judged = false;
    private String job;
    private double salary = 0;
    private Calendar dataOfGettingJob = null;

    public void setName(String name) {
        this.name = name;
    }

    public void setSurname(String surname) {
        this.surname = surname;
    }

    public void setBirthday(Calendar birthday) {
        this.birthday = birthday;
    }

    public void setSex(int sex) {
        this.sex = sex;
    }

    public void setEducation(String education) {
        this.education = education;
    }

    public void setMarried(boolean married) {
        this.married = married;
    }

    public void setChildren(int children) {
        this.children = children;
    }

    public void setJudged(boolean judged) {
        this.judged = judged;
    }

    public void setJob(String job) {
        this.job = job;
    }

    public void setSalary(double salary) {
        this.salary = salary;
    }

    public void setDataOfGettingJob(Calendar dataOfGettingJob) {
        this.dataOfGettingJob = dataOfGettingJob;
    }

    public static void showEditPanel() {
        System.out.println("1. Имя\n" +
                "2. Фамилия\n" +
                "3. Дата рождения \n" +
                "4. Пол\n" +
                "5. Образование\n" +
                "6. Семейное положение\n" +
                "7. Количество детей\n" +
                "8. Судимость\n" +
                "9. Работа\n");
    }

    @Override
    public String toString() {
        StringBuffer buffer = new StringBuffer();
        buffer.append("ID: ");
        buffer.append(id);
        buffer.append(" Name: ");
        buffer.append(name);
        buffer.append(" Surname: ");
        buffer.append(surname);
        buffer.append(" Birthday: ");
        buffer.append(birthday.get(Calendar.DATE));
        buffer.append("/");
        buffer.append(birthday.get(Calendar.MONTH));
        buffer.append("/");
        buffer.append(birthday.get(Calendar.YEAR));
        buffer.append(" Sex: ");
        if (sex == 0) {
            buffer.append("Male");
        } else {
            buffer.append("Female");
        }
        buffer.append(" Education: ");
        buffer.append(education);
        buffer.append(" Married: ");
        if (married) {
            buffer.append("Yes");
        } else {
            buffer.append("No");
        }
        buffer.append(" Children: ");
        buffer.append(children);
        if (judged) {
            buffer.append(" Judged: Yes");
        } else {
            buffer.append(" Judged: No");
        }
        buffer.append(" Job: ");
        buffer.append(job);
        if (!job.equals("null")) {
            buffer.append(" Salary: ");
            buffer.append(salary);
            buffer.append(" Date of start: ");
            buffer.append(dataOfGettingJob.get(Calendar.DAY_OF_MONTH));
            buffer.append("/");
            buffer.append(dataOfGettingJob.get(Calendar.MONTH));
            buffer.append("/");
            buffer.append(dataOfGettingJob.get(Calendar.YEAR));
        }
        buffer.append("\n");
        return new String(buffer);
    }

    public int getId() {
        return id;
    }

    public Calendar getBirthday() {
        return birthday;
    }

    public Man(String person) throws NumberFormatException ,NoSuchElementException{
        StringTokenizer parts = new StringTokenizer(person, " ", false);
        id = Integer.parseInt(parts.nextToken());
        name = parts.nextToken();
        surname = parts.nextToken();
        birthday = new GregorianCalendar();
        StringTokenizer data = new StringTokenizer(parts.nextToken(), "/", false);
        birthday.set(Calendar.DAY_OF_MONTH, Integer.parseInt(data.nextToken()));
        birthday.set(Calendar.MONTH, Integer.parseInt(data.nextToken()));
        birthday.set(Calendar.YEAR, Integer.parseInt(data.nextToken()));
        String temp = parts.nextToken();
        if (temp.equals("M")) {
            sex = 0;
        } else {
            sex = 1;
        }
        education = parts.nextToken();
        temp = parts.nextToken();
        if (temp.equals("Y")) {
            married = true;
        } else {
            married = false;
        }
        children = Integer.parseInt(parts.nextToken());
        temp = parts.nextToken();
        if (temp.equals("Y")) {
            judged = true;
        } else {
            judged = false;
        }
        job = parts.nextToken();
        if (!job.equals("null")) {
            salary = Double.parseDouble(parts.nextToken());
            dataOfGettingJob = new GregorianCalendar();
            data = new StringTokenizer(parts.nextToken(), ".", false);
            dataOfGettingJob.set(Calendar.DATE, Integer.parseInt(data.nextToken()));
            dataOfGettingJob.set(Calendar.MONTH, Integer.parseInt(data.nextToken()));
            dataOfGettingJob.set(Calendar.YEAR, Integer.parseInt(data.nextToken()));
        }


    }

    public boolean equalsName(String name) {
        return name.equals(this.name);
    }
    public String refact(){
        StringBuffer buffer=new StringBuffer();
        buffer.append(id).append(" ");
        buffer.append(name).append(" ");
        buffer.append(surname).append(" ");
        buffer.append(birthday.get(Calendar.DATE)).append("/").append(birthday.get(Calendar.MONTH)).append("/").append(birthday.get(Calendar.YEAR)).append(" ");
        if(sex==0){
            buffer.append("M").append(" ");
        }else{
            buffer.append("F").append(" ");
        }
        buffer.append(education).append(" ");
        if(married){
            buffer.append("Y").append(" ");
        }else{
            buffer.append("N").append(" ");
        }
        buffer.append(children).append(" ");
        if(judged){
            buffer.append("Y").append(" ");
        }else{
            buffer.append("N").append(" ");
        }
        if(job.equals("null")){
            buffer.append(job);
        }else {
            buffer.append(job).append(" ");
            buffer.append(salary).append(" ");
            buffer.append(dataOfGettingJob.get(Calendar.DATE)).append("/").append(dataOfGettingJob.get(Calendar.MONTH)).append("/").append(dataOfGettingJob.get(Calendar.YEAR)).append(" ");
        }
        return new String(buffer);


    }
}
