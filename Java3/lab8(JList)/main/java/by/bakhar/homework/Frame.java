package by.bakhar.homework;

import javax.swing.*;
import java.awt.*;

public class Frame extends JPanel {
    private final DefaultListModel<String> listModelLeft=new DefaultListModel<>();
    private final DefaultListModel<String> listModelRight=new DefaultListModel<>();
    private JList<String> jListLeft;
    private JList<String> jListRight;

    public Frame() {
        add(addJListsLeft(),BorderLayout.WEST);
        add(addCentralPanel(),BorderLayout.NORTH);
        add(addJListsRight(),BorderLayout.EAST);

    }

    private JPanel addJListsLeft() {
        JPanel panel=new JPanel();
        for (int i = 0; i < 10; i++) {
            listModelLeft.addElement("Left"+(i+1));
        }
        jListLeft = new JList<>(listModelLeft);
        panel.add(new JScrollPane(jListLeft,JScrollPane.VERTICAL_SCROLLBAR_AS_NEEDED,JScrollPane.HORIZONTAL_SCROLLBAR_NEVER));
        return panel;
    }
    private JPanel addJListsRight() {
        JPanel panel=new JPanel();
        for (int i = 0; i < 10; i++) {
            listModelRight.addElement("Right"+(i+1));
        }
        jListRight = new JList<>(listModelRight);
        panel.add(new JScrollPane(jListRight,JScrollPane.VERTICAL_SCROLLBAR_AS_NEEDED,JScrollPane.HORIZONTAL_SCROLLBAR_NEVER));
        return panel;
    }
    private JPanel addCentralPanel(){
        JPanel centralPanel=new JPanel(new BorderLayout());
        JButton jButtonToRight = new JButton(">");
        jButtonToRight.addActionListener(e -> {
            for (int i = 0; i < listModelLeft.size(); i++) {
                if(jListLeft.isSelectedIndex(i)){
                    listModelRight.addElement(listModelLeft.get(i));
                    listModelLeft.remove(i);
                    i--;
                }
            }
        });
        JButton jButtonToLeft = new JButton("<");
        jButtonToLeft.addActionListener(e -> {
            for (int i = 0; i < listModelRight.size(); i++) {
                if(jListRight.isSelectedIndex(i)){
                    listModelLeft.addElement(listModelRight.get(i));
                    listModelRight.remove(i);
                    i--;
                }
            }
        });
        centralPanel.add(jButtonToRight,BorderLayout.NORTH);
        centralPanel.add(jButtonToLeft,BorderLayout.SOUTH);
       return centralPanel;
    }
}
