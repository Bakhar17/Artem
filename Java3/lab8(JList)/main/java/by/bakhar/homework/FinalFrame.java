package by.bakhar.homework;

import javax.swing.*;

public class FinalFrame extends JFrame {
    public FinalFrame(){
        JPanel panel=new JPanel();
        JTabbedPane pane=new JTabbedPane();
        pane.addTab("Grid",new FrameGrid());
        pane.addTab("Radio",new FrameRadio());
        pane.addTab("JList",new Frame());
        panel.add(pane);
        add(panel);
        pack();
    }
}
