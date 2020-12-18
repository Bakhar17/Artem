package by.bakhar.bsu;

import javax.swing.*;
import java.awt.*;
import java.awt.Frame;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class InputDialog extends JDialog {
    private int id;
    private String surname;
    private String subject;
    private Double markS;
    private Student student;


    public InputDialog(Frame owner, MyDefaultListModel data) {
        super(owner);
        JPanel panel = new JPanel(new GridLayout(2, 2));


        JPanel panel1 = new JPanel(new FlowLayout());
        JTextField indic = new JTextField(15);
        JTextArea indicator = new JTextArea("indicator");
        panel1.add(indicator);
        panel1.add(indic);


        JPanel panel2 = new JPanel(new FlowLayout());
        JTextField name = new JTextField(15);
        JTextArea surnames = new JTextArea("surname");
        panel2.add(surnames);
        panel2.add(name);


        JPanel panel3 = new JPanel(new FlowLayout());
        JTextField sub = new JTextField(15);
        JTextArea subjects = new JTextArea("subject");
        panel3.add(subjects);
        panel3.add(sub);


        JPanel panel4 = new JPanel(new FlowLayout());
        JTextField mark = new JTextField(15);
        JTextArea marks = new JTextArea("mark");
        panel4.add(marks);
        panel4.add(mark);

        panel.add(panel1);
        panel.add(panel2);
        panel.add(panel3);
        panel.add(panel4);
        add(panel, BorderLayout.NORTH);
        JPanel buttonPanel = new JPanel();
        JButton jButton = new JButton("Добавить");
        jButton.addActionListener(e -> {
            try {
                id = Integer.parseInt(indic.getText());
                surname = name.getText();
                subject = sub.getText();
                markS = Double.parseDouble(mark.getText());
                if (markS > 0.0 && markS <= 10.0) {
                    student = new Student(id, surname);
                    student.addResult(subject, markS);
                    if (data.contains(student)) {
                        Student student1 = data.getElementAt(data.indexOf(student));
                        String temp = (String) student.getResults().keySet().toArray()[0];
                        Double temp1 = student.getResults().get(temp);
                        student1.addResult(temp, temp1);

                    } else {
                        data.addElement(student);
                    }
                    JOptionPane.showMessageDialog(null, "Студент был добавлен!");
                } else {
                    throw new ArithmeticException();
                }

            } catch (NumberFormatException | ArithmeticException w) {
                JOptionPane.showMessageDialog(null, "Данные не были записаны!");
            } finally {
                dispose();
            }

        });
        setVisible(true);
        buttonPanel.add(jButton);
        add(buttonPanel, BorderLayout.SOUTH);
        pack();
    }
}
