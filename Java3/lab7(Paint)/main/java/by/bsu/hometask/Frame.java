package by.bsu.hometask;

import javax.imageio.ImageIO;
import javax.swing.*;
import javax.swing.filechooser.FileNameExtensionFilter;
import java.awt.*;
import java.awt.event.*;
import java.awt.image.RenderedImage;
import java.io.File;
import java.io.FileFilter;
import java.io.IOException;

public class Frame extends JFrame {
    private DrawPanel drawPanel;
    private Color color;
    private JScrollPane jScrollPane;

    public Frame() {
        setTitle("Mini Paint");
        setSize(new Dimension(400, 800));
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        setLocationRelativeTo(null);

    }

    private void addDrawPanel() {
        drawPanel = new DrawPanel();
        jScrollPane = new JScrollPane(drawPanel, JScrollPane.VERTICAL_SCROLLBAR_AS_NEEDED, JScrollPane.HORIZONTAL_SCROLLBAR_AS_NEEDED);
        add(jScrollPane);
    }

    private void addMenuBar() {
        JMenuBar barMenu = new JMenuBar();
        JMenu menu = new JMenu("Options");
        JMenuItem menuItem = new JMenuItem("Choose colour");
        menuItem.addActionListener(e -> {
            color = JColorChooser.showDialog(null, "Colour", color);
            drawPanel.setColor(color);
        });
        JMenuItem menuItem2 = new JMenuItem("Open JPG");
        menuItem2.addActionListener(e -> {
            JFileChooser jFileChooser = new JFileChooser();
            jFileChooser.setAcceptAllFileFilterUsed(false);
            FileNameExtensionFilter filter = new FileNameExtensionFilter(
                    "Picture", "jpg", "jpeg","png");
            jFileChooser.setFileFilter(filter);
            int result = jFileChooser.showOpenDialog(null);
            if (result == JFileChooser.APPROVE_OPTION) {

                try{
                    drawPanel.setBi(ImageIO.read(jFileChooser.getSelectedFile()));
                    jScrollPane.repaint();
                } catch (IOException ioException) {
                   ioException.printStackTrace();
                }
            }
        });
        JMenuItem menuItem3 = new JMenuItem("Save PNG");
        menuItem3.addActionListener(e -> {
            JFileChooser jFileChooser = new JFileChooser();
            jFileChooser.setFileFilter(new FileNameExtensionFilter("PNG","png"));
            int result = jFileChooser.showSaveDialog(null);
                if(result==JFileChooser.APPROVE_OPTION){
                    File file =jFileChooser.getSelectedFile();
                    try {
                        ImageIO.write((RenderedImage) drawPanel.getBi(), "PNG", new File(file + ".png"));
                    } catch (IOException ioException) {
                        ioException.printStackTrace();
                    }
                }


        });
        menu.add(menuItem);
        menu.add(menuItem2);
        menu.add(menuItem3);
        barMenu.add(menu);
        this.setJMenuBar(barMenu);
    }

    public void createFrame() {
        addMenuBar();
        addDrawPanel();
    }
}
