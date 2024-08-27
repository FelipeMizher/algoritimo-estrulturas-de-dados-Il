import java.util.Scanner;
import java.io.File;
import java.io.FileNotFoundException;

public class readCSV{
    public static void main(String[] args){
        try{
            Scanner sc = new Scanner(new File("C:/Users/felip_000/Desktop/exercicos/TP_2/characters.csv"));
            int x = 0;
            String line;

            sc.nextLine();
            sc.useDelimiter(";");

            while(sc.hasNext() && x < 10){
                line = sc.nextLine();
                System.out.println(line);
                System.out.println();
                x++;
            }
            sc.close();
        } catch(FileNotFoundException e){
            System.out.println("Arquivo não encontrado!");
            e.printStackTrace();
        }
    }
}
