package by.bsu.hometask;

import javax.swing.*;
import java.awt.*;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.awt.event.MouseMotionListener;
import java.awt.image.BufferedImage;

public class DrawPanel extends JPanel implements MouseListener, MouseMotionListener {


    private BufferedImage bi;
    private int x1, y1, x2, y2;
    private boolean flag = false;
    private boolean drawAbillity = false;
    private Color color;

    public void setColor(Color color) {
        this.color = color;
    }

    public Image getBi() {
        return bi;
    }

    public void setBi(BufferedImage bi) {
        this.bi = bi;
        setPreferredSize(new Dimension(bi.getWidth(),bi.getHeight()));
    }

    public DrawPanel() {
        bi = new BufferedImage(1000, 1000, BufferedImage.TYPE_INT_RGB);
        Graphics gr = bi.getGraphics();
        gr.setColor(Color.YELLOW);
        gr.fillRect(0, 0, 1000, 1000);
        this.setPreferredSize(new Dimension(1000, 1000));
        this.addMouseListener(this);
        this.addMouseMotionListener(this);
    }

    @Override
    protected void paintComponent(Graphics g) {
        super.paintComponent(g);
        g.drawImage(bi, 0, 0, null);
    }

    @Override
    public void mouseClicked(MouseEvent e) {
        x1 = e.getX();
        y1 = e.getY();
        Graphics graphics = bi.getGraphics();
        graphics.setColor(color);
        graphics.drawLine(x1, y1, x1, y1);
        this.repaint();
    }

    @Override
    public void mousePressed(MouseEvent e) {
        x1 = e.getX();
        y1 = e.getY();
    }

    @Override
    public void mouseReleased(MouseEvent e) {

    }

    @Override
    public void mouseEntered(MouseEvent e) {
        drawAbillity = true;
    }

    @Override
    public void mouseExited(MouseEvent e) {
        drawAbillity = false;
    }

    @Override
    public void mouseDragged(MouseEvent e) {
        if (drawAbillity) {
            Graphics graphics = bi.getGraphics();
            x2 = e.getX();
            y2 = e.getY();
            graphics.setColor(color);
            graphics.drawLine(x1, y1, x2, y2);
            x1 = x2;
            y1 = y2;
            this.repaint();
        }
    }

    @Override
    public void mouseMoved(MouseEvent e) {
    }
}
