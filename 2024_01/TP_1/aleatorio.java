import java.util.Random;
import java.util.Scanner;

public class aleatorio{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        String line;

        Random gerador = new Random();
        gerador.setSeed(4);

        while(!(line = sc.nextLine()).equals("FIM")){
            StringBuilder novaString = new StringBuilder();
            char letra1 = (char) ('a' + (Math.abs(gerador.nextInt()) % 26));
            char letra2 = (char) ('a' + (Math.abs(gerador.nextInt()) % 26));

            for(int i = 0; i < line.length(); i++){
                char c = line.charAt(i);
                if(c == letra1){
                    novaString.append(letra2);
                } else{
                    novaString.append(c);
                }
            }

            System.out.println(novaString.toString());
        }

        sc.close();
    }
}