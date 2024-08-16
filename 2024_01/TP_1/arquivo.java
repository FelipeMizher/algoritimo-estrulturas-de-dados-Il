import java.io.IOException;
import java.io.RandomAccessFile;
import java.text.DecimalFormat;
import java.util.Scanner;

public class arquivo{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        DecimalFormat df = new DecimalFormat("#.###");
        double numero;
        int n = 0;
        String arqName = "numeros.txt";

        n = sc.nextInt();

        try(RandomAccessFile raf = new RandomAccessFile(arqName, "rw")){
            
            for(int i = 0; i < n; i++){
                numero = sc.nextDouble();
                raf.writeDouble(numero);
            }

            raf.seek(0);

            for(int i = 0; i < n; i++){
                raf.seek(raf.length() - (i + 1) * 8);
                numero = raf.readDouble();
                System.out.println(df.format(numero));
            }

        } catch(IOException erro){
            System.out.println("Erro: " + erro.getMessage());
        }
        
      sc.close();
    }
}