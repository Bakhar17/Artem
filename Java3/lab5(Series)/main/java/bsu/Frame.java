package bsu;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.ItemEvent;
import java.awt.event.ItemListener;
import java.io.File;
import java.io.IOException;

class Frame extends JFrame {
    private final Series[] series;
    private int itemNumber = 0;
    private Container container;
    private JTextField[] infoFields;

    private void createComboBox() {
        JComboBox<String> jComboBox = new JComboBox<>(new String[]{"Liner", "Exponential"});
        jComboBox.addItemListener(new ItemListener() {
            @Override
            public void itemStateChanged(ItemEvent e) {
                if (e.getItem().equals("Liner")) {
                    itemNumber = 0;
                } else {
                    itemNumber = 1;
                }
                updateInfoPanel();
            }
        });
        JPanel comboBox = new JPanel();
        comboBox.add(jComboBox);
        container = getContentPane();
        container.add(comboBox, BorderLayout.WEST);
    }

    private void createInfoPanel() {
        infoFields = new JTextField[2];
        infoFields[0] = new JTextField("first=" + series[itemNumber].getFirst());
        infoFields[0].setEditable(false);
        infoFields[1] = new JTextField("denominator=" + series[itemNumber].getDenominator());
        infoFields[1].setEditable(false);
        JButton buttonSaveToFile = new JButton("Save to file");
        buttonSaveToFile.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                JFileChooser fileopen = new JFileChooser();

                int ret = fileopen.showDialog(null, "Выберете файл");
                if (ret == JFileChooser.APPROVE_OPTION) {
                    File file = fileopen.getSelectedFile();
                    try {
                        series[itemNumber].saveToFile(file);
                    } catch (IOException ioException) {
                        ioException.printStackTrace();
                    }
                }

            }
        });
        JPanel infoPanel = new JPanel();
        infoPanel.setLayout(new BoxLayout(infoPanel, BoxLayout.Y_AXIS));
        infoPanel.add(infoFields[0]);
        infoPanel.add(infoFields[1]);
        infoPanel.add(buttonSaveToFile);
        container = getContentPane();
        container.add(infoPanel, BorderLayout.EAST);
    }

    private void updateInfoPanel() {
        infoFields[0].setText("first=" + series[itemNumber].getFirst());
        infoFields[1].setText("denominator=" + series[itemNumber].getDenominator());
    }

    private void createFunctionPanel() {
        JPanel functionPanel = new JPanel(new BorderLayout());

        JPanel buttonPanel = new JPanel(new FlowLayout());
        JButton buttonFirst = new JButton("Set first");
        JTextField textFirst = new JTextField(5);
        buttonFirst.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                series[itemNumber].setFirst(Reader.readData(textFirst));
                textFirst.setText("");
                updateInfoPanel();
            }
        });

        JButton buttonDenominator = new JButton("Set denominator");
        JTextField textDenominator = new JTextField(5);
        buttonDenominator.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                series[itemNumber].setDenominator(Reader.readData(textDenominator));
                textDenominator.setText("");
                updateInfoPanel();
            }
        });
        buttonPanel.add(buttonFirst);
        buttonPanel.add(textFirst);
        buttonPanel.add(buttonDenominator);
        buttonPanel.add(textDenominator);

        JPanel showPanel = new JPanel(new FlowLayout());
        JButton buttonShow = new JButton("Show");
        JTextField textSeries = new JTextField(20);
        textSeries.setEditable(false);
        buttonShow.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                textSeries.setText(series[itemNumber].toString());
            }
        });
        showPanel.add(buttonShow);
        showPanel.add(textSeries);

        functionPanel.add(buttonPanel, BorderLayout.NORTH);
        functionPanel.add(showPanel, BorderLayout.WEST);

        container = getContentPane();
        container.add(functionPanel, BorderLayout.SOUTH);
    }

    public Frame(Series[] series) {
        super("My Series");
        this.series = series;
        createComboBox();
        createInfoPanel();
        createFunctionPanel();
    }
}
