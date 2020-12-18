package by.bakhar.bsu;

import org.xml.sax.Attributes;
import org.xml.sax.SAXException;
import org.xml.sax.helpers.DefaultHandler;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;

public class StudentHandler extends DefaultHandler {
    private List<Student> students = new ArrayList<>();
    private Student current;
    private String currentTag;
    @Override
    public void startDocument() {
        System.out.println("startDocument");
    }

    public List<Student> getStudents() {
        return students;
    }

    @Override
    public void startElement(String uri, String localName, String qName,
                             Attributes attrs) {
        System.out.println("startElement: " + localName);
        currentTag = localName;
        switch (localName) {
            case "student":
                current = new Student();
                break;
            case "subject":
                current.addResult(attrs.getValue(0),Double.parseDouble(attrs.getValue(1)));
        }
    }

    @Override
    public void characters(char[] ch, int start, int length) {
        System.out.println("characters: " + currentTag);
        String s = new String(ch, start, length).trim();
        System.out.println("s = " + s);

        if (currentTag.equals("id")) {
            current.setIndicator(Integer.parseInt(s));
            currentTag = "";
        }
        if (currentTag.equals("surname")) {
            current.setSurname(s);
            currentTag = "";
        }
    }

    @Override
    public void endElement(String uri, String localName, String qName) {
        System.out.println("endElement " + current);
        if ("student".equals(localName)) {
            students.add(current);
        }
    }

    @Override
    public void endDocument() throws SAXException {
        System.out.println("endDocument");
    }
}
