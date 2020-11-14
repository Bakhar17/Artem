package bsu;
import java.util.StringTokenizer;

public class Main {
    public static StringBuffer refactoring(StringTokenizer token) {
        StringBuffer result = new StringBuffer();
        StringBuffer temp=new StringBuffer();
        while (token.hasMoreTokens()) {
            temp.delete(0,temp.length());
            temp.append(token.nextToken());
            if(temp.charAt(0)!='.'){
                result.append(delete(temp));
            }else{
                result.append(".");
            }
        }

        return result;
    }

    public static StringBuffer delete(StringBuffer text) {
        if (checkSubstring(text)) {
            int n = 0;
            for (int k = 2; k < text.length(); k++) {
                if (!Character.isDigit(text.charAt(k))) break;
                n++;
            }
            text.delete(2, 2 + n);
        }
        return text;
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
