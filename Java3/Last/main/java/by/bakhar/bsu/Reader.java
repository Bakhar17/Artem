package by.bakhar.bsu;

import javax.swing.*;
import java.util.Scanner;

public class Reader {
    public static void readTxt(Scanner scanner,MyDefaultListModel data) {
        String[] temp;
        if(!data.isEmpty()){
            data.removeAllElements();
        }
        while (scanner.hasNextLine()) {
            temp = scanner.nextLine().split(" ");
            try {
                Student check = new Student(Integer.parseInt(temp[0]), temp[1]);
                if (data.contains(check)) {
                    check = data.getElementAt(data.indexOf(check));
                    check.addResult(temp[2], Double.parseDouble(temp[3]));
                } else {
                    check.addResult(temp[2], Double.parseDouble(temp[3]));
                    data.addElement(check);
                }
            } catch (NumberFormatException e) {
                continue;
            }
        }
        data.sort();
    }
}
