import java.util.regex.*;
import java.util.*;

public class Ex3 {
    public static void main(String[] args) {
        // 1.
        // Pattern est un conteneur pour une représentation compilée d'une
        // expression régulière. Sa méthode compile() sert à en générer un
        // d'après une représentation textuelle.
        // Matcher est un conteneur pour la correspondance entre un
        // Pattern et une chaîne de caractères.
        //
        // 2.
        // for(String arg : args)
        //     if(Pattern.compile("\\d+").matcher(arg).matches())
        //         System.out.print(arg + " ");
        // 3.
        // for(String arg : args) {
        //     Matcher m = Pattern.compile("\\D*(?<nombre>\\d+)").matcher(arg);
        //     if(m.matches())
        //         System.out.print(m.group("nombre"));
        // }
        //
        // 4.
        byte[] ip = bytesFromIPv4String(args[0]);
        if(ip != null)
            System.out.println(unsignedBytesToString(ip, "."));
        else
            System.out.println("Not an IPv4 address!");
    }
    
    public static byte[] bytesFromIPv4String(String s) {
        String b = "(\\d{1,3})"; // b comme byte
        String d = "\\.";           // d comme dot
        Matcher m = Pattern.compile(b+d+b+d+b+d+b).matcher(s);

        if(!m.matches())
            return null;
        
        byte[] ip = new byte[4];
        for(int i=0 ; i<4 ; ++i) {
            int x = Integer.parseInt(m.group(1+i));
            if(x<0 || x>255)
                return null;
            ip[i] = (byte) x;
        }
        return ip;
    }

    public static String unsignedBytesToString(byte[] bytes, String sep) {
        String s = new String();
        for(int i=0 ; i<bytes.length ; ++i)
            s = s + (((int)bytes[i])&0xff) + (i<bytes.length-1 ? sep : "");
        return s;
    }

}
