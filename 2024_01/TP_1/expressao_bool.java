import java.util.Scanner;

public class expressao_bool{

    public static boolean isFim(String input) {
        return input.equals("0");
    }

    public static int avaliarExpressao(String expressao) {
        char operador = expressao.charAt(0);
        String valores = expressao.substring(2);

        for (char valor : valores.toCharArray()) {
            if (valor == '0' && operador == 'A') {
                return 0; 
            } else if (valor == '1' && operador == 'O') {
                return 1;
            }
        }

        return (operador == 'A') ? 1 : 0;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        while (true) {
            int numEntradas = Integer.parseInt(scanner.nextLine());

            if (numEntradas == 0) {
                break; 
            }

            String entrada = scanner.nextLine();
            int resultado = avaliarExpressao(entrada);
            System.out.println(resultado);
        }

        scanner.close();
    }
}
