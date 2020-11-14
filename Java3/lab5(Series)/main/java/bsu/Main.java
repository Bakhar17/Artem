package bsu;

import javax.swing.*;

public class Main {
    public static void main(String[] args) {
        Series[] series=new Series[]{new Liner(0,0),new Exponential(0,0)};
        Frame frame=new Frame(series);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setResizable(false);
        ImageIcon icon=new ImageIcon("src\\icon.png");
        frame.setIconImage(icon.getImage());
        frame.pack();
        frame.setVisible(true);
    }
}
