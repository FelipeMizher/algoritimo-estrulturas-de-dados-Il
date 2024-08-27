import java.util.Scanner;

public class par_impar{
    public static char verificarNum(int num){
        
        if (num % 2 == 0){
            return 'P';       
        } else{
            return 'I';
        }
    }

    public static void main(String[] args){
        Scanner scanner = new Scanner(System.in);
        int num;

        do{
            num = scanner.nextInt();
            if(num != 0){
                System.out.println(verificarNum(num));
            }
        } while(num != 0);

        scanner.close();
    }
}
