package bsu;

import javax.swing.*;
import java.awt.event.KeyAdapter;
import java.awt.event.KeyEvent;

public class MyKeyAdapter extends KeyAdapter {
    private boolean flag;
    private JButton button;

    public boolean isFlag() {
        return flag;
    }

    public MyKeyAdapter(JButton jButton) {
        button = jButton;
    }
    @Override
    public void keyTyped(KeyEvent e) {
        if (e.getKeyChar()!='\b'&& button.isFocusPainted() ) {
            button.setText(button.getText() + e.getKeyChar());
        }
    }

    @Override
    public void keyPressed(KeyEvent e) {
        if (e.isControlDown()) {
            flag = true;
        }
    }

    @Override
    public void keyReleased(KeyEvent e) {

        switch (e.getKeyCode()) {
            case 17 -> flag = false;
            case 8 -> {
                if(button.isFocusPainted()){
                    StringBuffer buffer = new StringBuffer(button.getText());
                    if (buffer.length() != 0) {
                        buffer.deleteCharAt(buffer.length() - 1);
                    }
                    button.setText(new String(buffer));
                }

            }
        }
    }
}
