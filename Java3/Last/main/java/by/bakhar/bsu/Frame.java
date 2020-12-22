package by.bakhar.bsu;

import javax.swing.*;
import javax.swing.filechooser.FileNameExtensionFilter;
import java.awt.*;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Collections;
import java.util.HashMap;
import java.util.List;
import java.util.Scanner;

public class Frame extends JFrame {
    public MyDefaultListModel getListModelLeft() {
        return listModelLeft;
    }

    private MyDefaultListModel listModelLeft;
    private MyDefaultListModel rightModelLeft;
    private JList<Student> jListLeft;
    private JList<Student> jListRight;

    public Frame() {
        addMenuBar();
        setSize(new Dimension(800, 600));
        add(addJLists(), BorderLayout.CENTER);
    }

    private MyDefaultListModel takeExcellentStudents(MyDefaultListModel list) {
        MyDefaultListModel rightList = new MyDefaultListModel();
        HashMap<String, Double> results;
        for (Student student : list) {
            results = student.getResults();
            boolean flag = true;
            for (String keys : results.keySet()) {
                if (results.get(keys) < 9.0) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                rightList.addElement(student);
            }
        }
        rightList.sort();
        return rightList;
    }

    private void addMenuBar() {
        JMenuBar barMenu = new JMenuBar();
        JMenu menu = new JMenu("Файл");
        JMenuItem menuItem = new JMenuItem("Открыть");


        menuItem.addActionListener(e -> {
            JFileChooser jFileChooser = new JFileChooser();
            jFileChooser.setAcceptAllFileFilterUsed(false);
            FileNameExtensionFilter filter = new FileNameExtensionFilter(
                    "Session", "txt");
            jFileChooser.setFileFilter(filter);
            int result = jFileChooser.showOpenDialog(null);
            if (result == JFileChooser.APPROVE_OPTION) {
                File file = jFileChooser.getSelectedFile();
                try (Scanner scanner = new Scanner(file)) {
                    Reader.readTxt(scanner, listModelLeft);
                    jListLeft.setModel(listModelLeft);
                } catch (FileNotFoundException fileNotFoundException) {
                    fileNotFoundException.printStackTrace();
                }
            }
        });



        menu.add(menuItem);
        JMenuItem menuItem2 = new JMenuItem("Добавить");
        menuItem2.addActionListener(e -> {
            InputDialog inputDialog = new InputDialog(this, listModelLeft);
        });
        menu.add(menuItem2);
        JMenuItem menuItem3 = new JMenuItem("Отобрать лучших");
        menuItem3.addActionListener(e -> {
            rightModelLeft = takeExcellentStudents(listModelLeft);
            jListRight.setModel(rightModelLeft);
        });
        menu.add(menuItem3);
        JMenuItem menuItem4=new JMenuItem("XML");
        menuItem4.addActionListener(e -> {
            List<Student> studs = Collections.list(getListModelLeft().elements());
            try (PrintWriter pw = new PrintWriter("manual.xml")) {
                pw.println("<?xml version=\"1.0\" encoding=\"UTF-8\"?>");
                pw.println("<students>");
                for (Student st : studs) {
                    pw.println("<student>");
                    pw.println("    <id>" + st.getIndicator()+"</id>");
                    pw.println("    <surname>" + st.getSurname()
                            + "</surname>");
                    HashMap<String, Double> temp=st.getResults();
                    pw.println("<session>");
                    for (String key:temp.keySet()){
                        pw.println("<subject name=\""+key+"\" mark=\""+temp.get(key)+"\"></subject>");
                    }
                    pw.println("</session>");
                    pw.println("</student>");
                }
                pw.println("</students>");

            } catch (FileNotFoundException w) {
                w.printStackTrace();
            }
        });
        menu.add(menuItem4);
        barMenu.add(menu);
        this.setJMenuBar(barMenu);
    }

    private JPanel addJLists() {
        JPanel panel = new JPanel(new BorderLayout());
        jListLeft = new JList<>();
        listModelLeft = new MyDefaultListModel();
        jListLeft.setModel(listModelLeft);
        jListLeft.setPreferredSize(new Dimension(400, 500));
        panel.add(new JScrollPane(jListLeft, JScrollPane.VERTICAL_SCROLLBAR_AS_NEEDED, JScrollPane.HORIZONTAL_SCROLLBAR_AS_NEEDED), BorderLayout.WEST);
        jListRight = new JList<>();
        jListRight.setPreferredSize(new Dimension(400, 500));
        panel.add(new JScrollPane(jListRight, JScrollPane.VERTICAL_SCROLLBAR_AS_NEEDED, JScrollPane.HORIZONTAL_SCROLLBAR_AS_NEEDED), BorderLayout.EAST);
        return panel;
    }


}
