package by.bakhar.bsu;


import org.xml.sax.SAXException;
import org.xml.sax.XMLReader;
import org.xml.sax.helpers.XMLReaderFactory;

import javax.swing.*;
import java.io.IOException;
import java.util.List;

public class Main {
    public static void checkXML(){
        try {
            // создание SAX-анализатора
            XMLReader reader = XMLReaderFactory.createXMLReader();
            StudentHandler handler = new StudentHandler();
            reader.setContentHandler(handler);
            reader.parse("manual.xml");
            List<Student> check = handler.getStudents();
            System.out.println("check = " + check);
        } catch (SAXException e) {
            System.err.print("ошибка SAX парсера " + e);
        } catch (IOException e) {
            System.err.print("ошибка I/О потока " + e);
        }
    }
    public static void main(String[] args) {
        Frame frame = new Frame();
        frame.setLocationRelativeTo(null);
        frame.setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE);
        frame.setVisible(true);
        checkXML();
    }
}
