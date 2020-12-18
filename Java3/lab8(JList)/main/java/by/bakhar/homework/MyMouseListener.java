package by.bakhar.homework;

import javax.swing.*;
import java.awt.*;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;

public class MyMouseListener extends MouseAdapter {
    private String name;
    @Override
    public void mousePressed(MouseEvent e) {
        JButton jButton=(JButton)e.getSource();
        name=jButton.getText();
        jButton.setText("Clicked!");
    }

    @Override
    public void mouseReleased(MouseEvent e) {
        JButton jButton=(JButton)e.getSource();
        jButton.setText(name);
    }

    @Override
    public void mouseEntered(MouseEvent e) {
        JButton jButton=(JButton)e.getSource();
        jButton.setBackground(Color.BLUE);
    }

    @Override
    public void mouseExited(MouseEvent e) {
        JButton jButton=(JButton)e.getSource();
        jButton.setBackground(null);
    }
}
