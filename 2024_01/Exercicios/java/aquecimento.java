import java.util.Scanner;

public class aquecimento {
    public static int contarMaiusculo(String str){
        int count = 0;

        for(int i = 0; i < str.length(); i++){
            char c = str.charAt(i);
            if(Character.isUpperCase(c)){
                count++;
            }
        }
        return count;
    }

    public static void main(String[] args){
        Scanner scanner = new Scanner(System.in);
        String line;

        do{
            line = scanner.nextLine();
            if(!line.equals("FIM")){
                System.out.println(contarMaiusculo(line));
            }
        } while(!line.equals("FIM"));
        
        scanner.close();
    }
}
