import java.util.Scanner;

public class ciframento{
    public static String Ciframento(String str){
        StringBuilder cifra = new StringBuilder();         
        int i = 0;

        for(i = 0; i < str.length(); i++){
            char c = str.charAt(i);

            if(c >= ' ' && c <= '~'){
                c = (char)((c + 3) % 128);
            } else{
                cifra.append(c);
                continue;
            }

            cifra.append(c);
        }

      return cifra.toString();
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