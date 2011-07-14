import java.io.*;
import java.util.*;

public class T9 {
 
        /**
         * @param args
         */
 
        static HashMap<String, String> t9Map;
 
        public static void main(String[] args) throws NumberFormatException,
                        IOException {
 
                FileInputStream inFile = new FileInputStream(new File(
                                "C-small-practice.in"));
                DataInputStream in = new DataInputStream(inFile);
                FileOutputStream outFile = new FileOutputStream(new File("out.txt"));
                DataOutputStream out = new DataOutputStream(outFile);
 
                int cases = Integer.parseInt(in.readLine());
 
                t9Map = new HashMap<String, String>();
                fillMap();
 
                for (int i = 1; i <= cases; i++) {
                        out.writeBytes("Case #" + i + ": ");
                        String t9, t9last = "";
 
                        String text = in.readLine();
                        for (int j = 0; j < text.length(); j++) {
 
                                t9 = t9Map.get(String.valueOf(text.charAt(j)));
                               
                                // do we need a break? (letters are on same button)
                                if (j > 0 && (t9.charAt(0)) == t9last.charAt(0)) {
                                        out.writeBytes(" ");
                                }
 
                                out.writeBytes(t9);
                                t9last = t9;
                        }
                        out.writeBytes("\n");
                }
 
        }
 
        public static void fillMap() {
                t9Map.put("a", "2");
                t9Map.put("b", "22");
                t9Map.put("c", "222");
                t9Map.put("d", "3");
                t9Map.put("e", "33");
                t9Map.put("f", "333");
                t9Map.put("g", "4");
                t9Map.put("h", "44");
                t9Map.put("i", "444");
                t9Map.put("j", "5");
                t9Map.put("k", "55");
                t9Map.put("l", "555");
                t9Map.put("m", "6");
                t9Map.put("n", "66");
                t9Map.put("o", "666");
                t9Map.put("p", "7");
                t9Map.put("q", "77");
                t9Map.put("r", "777");
                t9Map.put("s", "7777");
                t9Map.put("t", "8");
                t9Map.put("u", "88");
                t9Map.put("v", "888");
                t9Map.put("w", "9");
                t9Map.put("x", "99");
                t9Map.put("y", "999");
                t9Map.put("z", "9999");
                t9Map.put(" ", "0");
        }
 
}
