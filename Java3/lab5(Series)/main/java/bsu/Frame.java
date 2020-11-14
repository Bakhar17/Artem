package bsu;

import javax.swing.*;
import java.awt.*;
import java.io.File;
import java.io.IOException;

class Frame extends JFrame {
    private Series series;
    private Container container;
    private JTextField[] infoFields;

    private void createComboBox() {
        JComboBox<String> jComboBox = new JComboBox<>(new String[]{"Liner", "Exponential"});
        jComboBox.addItemListener(e -> {
            if (e.getItem().equals("Liner")) {
                series=new Liner(0,0);
            } else {
                series=new Exponential(0,0);
            }
            updateInfoPanel();
        });
        JPanel comboBox = new JPanel();
        comboBox.add(jComboBox);
        container = getContentPane();
        container.add(comboBox, BorderLayout.WEST);
    }

    private void createInfoPanel() {
        infoFields = new JTextField[2];
        infoFields[0] = new JTextField("first=" + series.getFirst());
        infoFields[0].setEditable(false);
        infoFields[1] = new JTextField("denominator=" + series.getDenominator());
        infoFields[1].setEditable(false);
        JButton buttonSaveToFile = new JButton("Save to file");
        buttonSaveToFile.addActionListener(e -> {
            JFileChooser fileopen = new JFileChooser();

            int ret = fileopen.showDialog(null, "Выберете файл");
            if (ret == JFileChooser.APPROVE_OPTION) {
                File file = fileopen.getSelectedFile();
                try {
                    series.saveToFile(file);
                } catch (IOException ioException) {
                    ioException.printStackTrace();
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
        infoFields[0].setText("first=" + series.getFirst());
        infoFields[1].setText("denominator=" + series.getDenominator());
    }

    private void createFunctionPanel() {
        JPanel functionPanel = new JPanel(new BorderLayout());

        JPanel buttonPanel = new JPanel(new FlowLayout());
        JButton buttonFirst = new JButton("Set first");
        JTextField textFirst = new JTextField(5);
        buttonFirst.addActionListener(e -> {
            series.setFirst(Reader.readData(textFirst));
            textFirst.setText("");
            updateInfoPanel();
        });

        JButton buttonDenominator = new JButton("Set denominator");
        JTextField textDenominator = new JTextField(5);
        buttonDenominator.addActionListener(e -> {
            series.setDenominator(Reader.readData(textDenominator));
            textDenominator.setText("");
            updateInfoPanel();
        });
        buttonPanel.add(buttonFirst);
        buttonPanel.add(textFirst);
        buttonPanel.add(buttonDenominator);
        buttonPanel.add(textDenominator);

        JPanel showPanel = new JPanel(new FlowLayout());
        JButton buttonShow = new JButton("Show");
        JTextField textSeries = new JTextField(20);
        textSeries.setEditable(false);
        buttonShow.addActionListener(e -> textSeries.setText(series.toString()));
        showPanel.add(buttonShow);
        showPanel.add(textSeries);

        functionPanel.add(buttonPanel, BorderLayout.NORTH);
        functionPanel.add(showPanel, BorderLayout.WEST);

        container = getContentPane();
        container.add(functionPanel, BorderLayout.SOUTH);
    }

    public Frame() {
        super("My Series");
        series=new Liner(0,0);
        createComboBox();
        createInfoPanel();
        createFunctionPanel();
    }
}
