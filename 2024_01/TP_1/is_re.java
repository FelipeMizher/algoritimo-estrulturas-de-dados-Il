import java.util.Scanner;

public class is_re{
    private static boolean vogal(char c, char[] vogais) {
        for (char vogal : vogais) {
            if (c == vogal) {
                return true;
            }
        }
        return false;
    }

    private static boolean recursiveVogal(String str, char[] vogais, int index){
        if (index >= str.length()) {
            return true;
        }
        
        char letra = str.charAt(index);

        if (!vogal(letra, vogais)){
            return false;
        }

        return recursiveVogal(str, vogais, index + 1);
    }

    public static boolean vogais(String str){
        char[] vogais = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
      return recursiveVogal(str, vogais, 0);
    }

    private static boolean recursiveConsoante(String str, char[] vogais, int index){
        if(index >= str.length()){
            return true;
        }

        char letra = str.charAt(index);

        if(vogal(letra, vogais) || Character.isDigit(letra)){
            return false;
        }

        return recursiveConsoante(str, vogais, index + 1);
    }

    public static boolean consoantes(String str){
        char[] vogais = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
      return recursiveConsoante(str, vogais, 0);
    }

    private static boolean recursiveInteiros(String str, int index){
        if(index >= str.length()){
            return true;
        }

        char letra = str.charAt(index);

        if(!Character.isDigit(letra)){
            return false;
        }

        return recursiveInteiros(str, index + 1);
    }

    public static boolean inteiros(String str){
      return recursiveInteiros(str, 0);
    }

    public static boolean reais(String str){
        int i = 0;
        int j = str.length();
        boolean pontoDecimalEncontrado = false;

        for(i = 0; i < j; i++){
            char c = str.charAt(i);
            if(c == '.' || c == ','){
                if(pontoDecimalEncontrado){
                    return false; 
                }
                pontoDecimalEncontrado = true; 
            } else if(!Character.isDigit(c)){
                return false;
            }
        }

      return true;
    }

    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        String line;
        String vogal = "";
        String consoante = "";
        String inteiro = "";
        String reais = "";
        
        while(!(line = sc.nextLine()).equals("FIM")){
            if (vogais(line)){
                vogal = "SIM";
            } else{
                vogal = "NAO";
            }

            if (consoantes(line)){
                consoante = "SIM";
            } else{
                consoante = "NAO";
            }

            if (inteiros(line)){
                inteiro = "SIM";
            } else{
                inteiro = "NAO";
            }

            if (reais(line)){
                reais = "SIM";
            } else{
                reais = "NAO";
            } 

            System.out.println(vogal + " " + consoante + " " + inteiro + " " + reais);
        }

        sc.close();
    }
}
