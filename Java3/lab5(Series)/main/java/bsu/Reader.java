package bsu;

import javax.swing.*;

public class Reader {
    public static double readData(JTextField field){
        String text=field.getText();
        double data;
        try {
            data=Double.parseDouble(text);
        }catch (NumberFormatException e){
            data=0;
        }
        return data;
    }
}
