package by.bakhar.homework;

import javax.swing.*;
import java.awt.*;

public class FrameGrid extends JPanel {
    public FrameGrid() {
        setLayout(new GridLayout(3, 0, 5, 12));
        MyMouseListener buttonsListener = new MyMouseListener();
        for (int i = 0; i < 15; i++) {
            JButton[] jButtons = new JButton[15];
            jButtons[i]=new JButton("button"+i);
            jButtons[i].addMouseListener(buttonsListener);
            add(jButtons[i]);
        }
    }
}
