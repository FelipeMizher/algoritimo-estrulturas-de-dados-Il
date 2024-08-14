import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class pokemon{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int N, total, capturados;
        Set<String> pokemons = new HashSet<>();

        // System.out.println("Insira quantos pokemons voce tem: ");
        N = sc.nextInt();
        sc.nextLine();

        for(int i = 0; i < N; i++){
            // System.out.println("Qual o nome do pokemon: ");
            String pokemon = sc.nextLine();
            pokemons.add(pokemon);
        }

        capturados = pokemons.size();
        total = 151 - capturados;

        System.out.println("Falta(m) "+ total +" pomekon(s).");
        
      sc.close();
    }
}