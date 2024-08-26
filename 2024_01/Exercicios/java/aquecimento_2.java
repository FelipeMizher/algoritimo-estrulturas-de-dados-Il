import java.util.Scanner;

public class aquecimento_2 {
    public static int contarMaiusculo(String str){
        int count = 0;

        if(str.equals("")){
            return 0;
        }

        char primeiroCaractere = str.charAt(0);

        if(primeiroCaractere >= 'A' && primeiroCaractere <= 'Z'){
            count = 1;
        }

        return count + contarMaiusculo(str.substring(1));
    }

    public static void main(String[] args){
        Scanner scanner = new Scanner(System.in);
        String line;

        do {
            line = scanner.nextLine();
            if (!line.equals("FIM")) {
                int resultado = contarMaiusculo(line);
                if(resultado > 0) {
                    System.out.println(resultado);
                }
            }
        } while (!line.equals("FIM"));

        scanner.close();
    }
}
