package bsu;

public class Main {
    public static int posPoint(StringBuffer buf,int pos){
        for (int i = pos+1; i < buf.length(); i++) {
            if(buf.charAt(i)=='.'){
                pos =i;
                return pos;
            }
        }
        return -1;
    }
    public static boolean checkSubstring(StringBuffer buf,int pos){
        if(Character.isDigit(buf.charAt(pos+1))&& Character.isDigit(buf.charAt(pos+2))){
            return true;
        }
        return false;
    }
    public static void main(String[] args) {
        StringBuffer buf = new StringBuffer(args[0]);
        System.out.println(buf);
        return;
    }
}
