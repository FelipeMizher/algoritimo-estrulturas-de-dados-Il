import java.util.Scanner;

public class palindromo{
    public static boolean Palindromo(String str){
        int i = 0;
        int j = str.length() - 1;

        while(i < j){
            if(str.charAt(i) != str.charAt(j)){
                return false;
            } 
            i++;
            j--;
        }
        return true;
    }

    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        String line;

        while (!(line = sc.nextLine()).equals("FIM")) {
            if (Palindromo(line)) {
                System.out.println("SIM");
            } else {
                System.out.println("NAO");
            }
        }

        sc.close();
    }
}
