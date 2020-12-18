package by.bakhar.homework;

import javax.swing.*;
import java.awt.*;

public class FrameRadio extends JPanel {

    public FrameRadio() {
        ButtonGroup radioButtons = new ButtonGroup();
        JRadioButton jRadioButton1 = new JRadioButton("sjf", new ImageIcon("src/icon.jpeg"), false);
        JRadioButton jRadioButton2 = new JRadioButton("sjf", new ImageIcon("src/icon.jpeg"), false);
        radioButtons.add(jRadioButton1);
        radioButtons.add(jRadioButton2);
        jRadioButton1.setDisabledIcon(new ImageIcon("src/icon.jpeg"));
        jRadioButton2.setDisabledIcon(new ImageIcon("src/icon.jpeg"));
        jRadioButton1.setSelectedIcon(new ImageIcon("src/icon3.jpg"));
        jRadioButton2.setSelectedIcon(new ImageIcon("src/icon3.jpg"));
        jRadioButton1.setRolloverIcon(new ImageIcon("src/icon4.jpg"));
        jRadioButton2.setRolloverIcon(new ImageIcon("src/icon4.jpg"));
        jRadioButton1.setRolloverSelectedIcon(new ImageIcon("src/icon5.jpg"));
        jRadioButton2.setRolloverSelectedIcon(new ImageIcon("src/icon5.jpg"));
        add(jRadioButton1);
        add(jRadioButton2);
    }


}
