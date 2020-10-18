package bsu;
import java.util.StringTokenizer;

public class Main {
    public static StringBuffer refactoring(StringTokenizer token) {
        StringBuffer result = new StringBuffer();
        result.append(token.nextToken());
        while (token.hasMoreTokens()) {
            result.append(token.nextToken());
            result.append(delete(token.nextToken()));
        }
        return result;
    }

    public static StringBuffer delete(String text) {
        StringBuffer temp = new StringBuffer(text);
        if (checkSubstring(temp)) {
            int n = 0;
            for (int k = 2; k < temp.length(); k++) {
                if (!Character.isDigit(temp.charAt(k))) break;
                n++;
            }
            temp.delete(2, 2 + n);
        }
        return temp;
    }

    public static boolean checkSubstring(StringBuffer buf) {
        if (buf.length() > 2) {
            if (Character.isDigit(buf.charAt(0)) && Character.isDigit(buf.charAt(1))) {
                return true;
            }
        }
        return false;
    }

    public static void main(String[] args) {
        StringTokenizer token = new StringTokenizer(args[0], ".", true);
        StringBuffer buf = new StringBuffer(refactoring(token));
        System.out.println(buf);
        return;
    }
}
