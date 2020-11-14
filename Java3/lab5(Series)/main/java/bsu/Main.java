package bsu;

import javax.swing.*;

public class Main {
    public static void main(String[] args) {
        Frame frame=new Frame();
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setResizable(false);
        ImageIcon icon=new ImageIcon("src\\icon.png");
        frame.setIconImage(icon.getImage());
        frame.pack();
        frame.setVisible(true);
    }
}
