import java.util.Scanner;

public class palindromo{
    private static boolean recursive(String str, int I, int F){
        if(I >= F){
            return true;
        }

        if(str.charAt(I) != str.charAt(F)){
            return false;
        }

      return recursive(str, I + 1, F);
    }

    public static boolean Palindromo(String str){
        return recursive(str, 0, str.length());
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
