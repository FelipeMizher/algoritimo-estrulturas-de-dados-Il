import java.util.Scanner;

public class is{
    public static boolean vogais(String str){
        char[] vogais = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        int i = 0;
        int j = str.length() - 1;

        while(i < j){
            boolean Vogal = false;
            for(char vogal : vogais){
                if(str.charAt(i) == vogal){
                    Vogal = true;
                }
            }
            if(!Vogal){
                return false;
            }
            i++;
        }
      return true;
    }

    public static boolean consoantes(String str){
        char[] vogais = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        int i = 0;
        int j = str.length() - 1;

        while(i < j){
            boolean consoante = true;
            for(char vogal : vogais){
                if(str.charAt(i) == vogal || Character.isDigit(str.charAt(i))){
                    consoante = false;
                }
            }
            if(!consoante){
                return false;
            }
            i++;
        }
      return true;
    }

    public static boolean inteiros(String str){
        int i = 0;
        int j = str.length();
    
        for(i = 0; i < j; i++){
            if(!Character.isDigit(str.charAt(i))){
                return false;
            }
        }
        
      return true;
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
