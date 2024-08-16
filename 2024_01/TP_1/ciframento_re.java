import java.util.Scanner;

public class ciframento_re{
    public static String Ciframento(String str){
        if(str.isEmpty()){
            return "";
        } else{
            char c = str.charAt(0);
            StringBuilder cifra = new StringBuilder();
    
            if(c >= ' ' && c <= '~'){
                c = (char)((c + 3) % 128);
            }
            
            cifra.append(c);
    
            return cifra.toString() + Ciframento(str.substring(1));
        }
    }

    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        String line;

        while(!(line = sc.nextLine()).equals("FIM")){
            System.out.println("" + Ciframento(line));
        }

        sc.close();
    }
}