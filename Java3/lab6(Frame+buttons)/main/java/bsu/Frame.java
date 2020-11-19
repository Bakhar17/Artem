package bsu;

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class Frame {

    public static JFrame createFrame1() {
        JFrame frame = new JFrame("Lab 6.1");
        frame.setResizable(false);
        frame.setLocationRelativeTo(null);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(new Dimension(600, 380));

        JPanel infoPanel = new JPanel();
        JLabel text = new JLabel();
        infoPanel.add(text);
        frame.add(infoPanel, BorderLayout.SOUTH);
        JPanel buttonPanel = new JPanel(null);
        JButton button = new JButton("button");
        button.setLocation(100, 50);
        button.setSize(100, 30);
        buttonPanel.add(button);
        frame.add(buttonPanel, BorderLayout.CENTER);


        buttonPanel.addMouseMotionListener(new MouseAdapter() {
            @Override
            public void mouseMoved(MouseEvent e) {
                Point point = e.getPoint();
                int x = point.x;
                int y = point.y;
                text.setText("x: " + x + " y: " + y);
            }
        });
        buttonPanel.addMouseListener(new MouseAdapter() {
            @Override
            public void mouseReleased(MouseEvent e) {
                Point point = e.getPoint();
                int x = point.x;
                int y = point.y;
                button.setLocation(x - 50, y - 15);
                button.setFocusPainted(false);
            }
        });
        button.addActionListener(e -> button.setFocusPainted(!button.isFocusPainted()));
        MyKeyAdapter myKeyAdapter = new MyKeyAdapter(button);
        button.addKeyListener(myKeyAdapter);
        button.addMouseMotionListener(new MouseMotionAdapter() {
            @Override
            public void mouseDragged(MouseEvent e) {
                Point buttonPoint = new Point();
                button.getLocation(buttonPoint);
                Point point = e.getPoint();
                int x = point.x + buttonPoint.x;
                int y = point.y + buttonPoint.y;
                text.setText("x: " + x + " y: " + y);
                if (myKeyAdapter.isFlag()) {
                    button.setLocation(x - 50, y - 15);
                    button.setFocusPainted(false);
                }
            }

            @Override
            public void mouseMoved(MouseEvent e) {
                Point buttonPoint = new Point();
                button.getLocation(buttonPoint);
                Point point = e.getPoint();
                int x = point.x + buttonPoint.x;
                int y = point.y + buttonPoint.y;
                text.setText("x: " + x + " y: " + y);
            }
        });

        return frame;
    }

    public static JFrame createFrame2() {
        JFrame frame = new JFrame("Lab 6.2");
        frame.setResizable(false);
        frame.setLocationRelativeTo(null);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(new Dimension(550, 190));

        JLabel question = new JLabel("Довольны ли Вы стипендией?");
        JPanel questionPanel=new JPanel();
        questionPanel.add(question);
        frame.add(questionPanel,BorderLayout.NORTH);


        JButton yesButton=new JButton("Да");
        yesButton.addActionListener(e -> JOptionPane.showMessageDialog(frame,"Спасибо!","Кнопка 1", JOptionPane.INFORMATION_MESSAGE));
        yesButton.setSize(100, 30);
        yesButton.setLocation(100, 25);
        yesButton.setFocusPainted(false);
        JButton noButton=new JButton("Нет");
        noButton.setSize(100, 30);
        noButton.setLocation(300, 25);
        noButton.addMouseListener(new MouseAdapter() {
            private int xPos=1;
            private int yPos=1;
            @Override
            public void mouseEntered(MouseEvent e) {
                Point nowPoint= new Point();
                noButton.getLocation(nowPoint);
                nowPoint.x+=xPos*150;
                xPos*=-1;
                nowPoint.y+=yPos*15;
                yPos*=-1;
                noButton.setLocation(nowPoint);
            }
        });
        JPanel buttonsPanel=new JPanel(null);

        buttonsPanel.add(yesButton);
        buttonsPanel.add(noButton);
        frame.add(buttonsPanel,BorderLayout.CENTER);
        return frame;
    }

}
