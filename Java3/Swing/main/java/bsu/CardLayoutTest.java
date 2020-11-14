package bsu;
import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class CardLayoutTest implements ItemListener
{
    private static JPanel cards;

    final   static String BUTTONPANEL = "Панель с кнопками"       ;
    final   static String TEXTPANEL   = "Панель с текстовым полем";

    /**
     * Метод определения интерфейса панели
     * @param container - панель содержимого
     */
    public void createPanelUI(Container container)
    {
        // Создание компонента с выпадающим списком
        JComboBox<String> combobox = new JComboBox<String>(
                new String[] {BUTTONPANEL, TEXTPANEL});
        combobox.setEditable    (false);
        combobox.addItemListener(this );

        // Помещаем JComboBox в JPanel для наглядности.
        JPanel cbPanel = new JPanel();
        cbPanel.add(combobox);

        // Создание "cards".
        JPanel card1 = new JPanel();
        card1.add(new JButton("Продукты"));
        card1.add(new JButton("Одежда"  ));
        card1.add(new JButton("Обувь"   ));

        JPanel card2 = new JPanel();
        card2.add(new JTextField("TextField", 15));

        // Создаем панель с менеджером расположения CardLayout
        cards = new JPanel(new CardLayout());
        // Добавляем вкладки
        cards.add(card1, BUTTONPANEL);
        cards.add(card2, TEXTPANEL);

        container.add(cbPanel, BorderLayout.PAGE_START);
        container.add(cards  , BorderLayout.CENTER    );
    }
    // Обработчик события
    public void itemStateChanged(ItemEvent event)
    {
        CardLayout layout = (CardLayout)(cards.getLayout());
        layout.show(cards, (String)event.getItem());
    }

    public static void main(String[] args)
            throws ClassNotFoundException, InstantiationException,
            IllegalAccessException, UnsupportedLookAndFeelException
    {
        // Создание и настройка окна
        final JFrame frame = new JFrame("CardLayoutTest");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setResizable(false);
        javax.swing.SwingUtilities.invokeLater(new Runnable() {
            public void run() {
                (new CardLayoutTest()).createPanelUI(frame.getContentPane());

                // Открытие окна
                frame.pack();
                frame.setVisible(true);
            }
        });
    }
}