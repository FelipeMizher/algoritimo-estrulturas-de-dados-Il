import java.util.Scanner;

class Celula {
   public int elemento;
   public Celula inf, sup, esq, dir;

   public Celula(){
      this(0);
   }

   public Celula(int elemento){
      this(elemento, null, null, null, null);
   }

   public Celula(int elemento, Celula inf, Celula sup, Celula esq, Celula dir){
      this.elemento = elemento;
      this.inf = inf;
      this.sup = sup;
      this.esq = esq;
      this.dir = dir;
   }
}

public class matriz{
   private Celula inicio;
   private int linha, coluna;

   static Scanner sc = new Scanner(System.in);

   public matriz(){
      this(3, 3);
   }

   public matriz(int linha, int coluna){
      this.linha = linha;
      this.coluna = coluna;
      int i = 0, j = 0;
      inicio = new Celula();

      Celula tmpLinha = inicio; Celula tmpColuna = inicio; Celula tmpLink = inicio;
      while(j < coluna - 1){
         tmpColuna.dir = new Celula();
         tmpColuna.dir.esq = tmpColuna;
         tmpColuna = tmpColuna.dir;
         j++;
      } j = 0; tmpColuna = inicio;

      while(i < linha - 1){
         tmpLink = tmpLinha; 
         tmpLinha.inf = new Celula();    
         tmpLinha.inf.sup = tmpLinha;     
         tmpLinha = tmpLinha.inf;         
         tmpColuna = tmpLinha;            
         j = 0;
         while(j < coluna - 1){
            tmpColuna.dir = new Celula();
            tmpColuna.dir.esq = tmpColuna;
            tmpColuna = tmpColuna.dir;
            tmpLink = tmpLink.dir;
            tmpLink.inf = tmpColuna;    
            tmpLink.inf.sup = tmpLink;
            j++;
         }
         i++;
      } 
      tmpColuna = null;
      tmpLinha = null;
      tmpLink = null;
   }

   public void setLinha(int linha){
      this.linha = linha;
   }

   public void setColuna(int coluna){
      this.coluna = coluna;
   }

   public int getLinha(){
      return this.linha;
   }

   public int getColuna(){
      return this.coluna;
   }

   public void lerDados(){
      Celula tmp, tmpL;

      for(tmpL = inicio; tmpL != null; tmpL = tmpL.inf){
         for(tmp = tmpL; tmp != null; tmp = tmp.dir){
            tmp.elemento = sc.nextInt();
         }
      }
   }

   public void Exibir(){
      Celula tmp, tmpL;

      for(tmpL = inicio; tmpL != null; tmpL = tmpL.inf){
         for(tmp = tmpL; tmp != null; tmp = tmp.dir){
            System.out.print(tmp.elemento + " ");
         }
         System.out.print("\n");
      }
   }

   public matriz soma(matriz m){
      matriz resp = null;

      if(this.linha == m.linha && this.coluna == m.coluna){
         resp = new matriz(this.linha, this.coluna);
         Celula aLinha, bLinha, cLinha, a, b, c;
         for(aLinha = this.inicio, bLinha = m.inicio, cLinha = resp.inicio; 
            aLinha != null && bLinha != null && cLinha != null; 
            aLinha = aLinha.inf, bLinha = bLinha.inf, cLinha = cLinha.inf){
            for(a = aLinha, b = bLinha, c = cLinha; 
               a != null && b != null && c != null; 
               a = a.dir, b = b.dir, c = c.dir){
               c.elemento = a.elemento + b.elemento;
            }
         }
      } else{
         throw new IllegalArgumentException("As matrizes devem ter as mesmas dimensões para serem somadas.");
      }
      return resp;
   }

 
   public matriz multiplicacao(matriz m){
      matriz resp = new matriz(this.linha, m.coluna);
      Celula aLinha, a, bColuna, b, cLinha, c;

      for(aLinha = this.inicio, cLinha = resp.inicio; aLinha != null; aLinha = aLinha.inf, cLinha = cLinha.inf){
         for(bColuna = m.inicio, c = cLinha; bColuna != null; bColuna = bColuna.dir, c = c.dir){
            int soma = 0;
            for(a = aLinha, b = bColuna; a != null && b != null; a = a.dir, b = b.inf){
               soma += a.elemento * b.elemento;
            }
            c.elemento = soma;
         }
      }
      return resp;
   }

   public boolean Quadrada(){
      return (this.linha == this.coluna);
   }
 
   public void DiagonalP(){
      if(Quadrada()){
         Celula tmp = inicio;
         for(int i = 0; i < linha; i++){
            System.out.print(tmp.elemento + " ");
            if(tmp.dir != null && tmp.inf != null){
               tmp = tmp.dir.inf;
            }
         }
         System.out.println();
      }
   }

   public void DiagonalS(){
      if(Quadrada()){
         Celula tmp = inicio;
         while(tmp.dir != null){
            tmp = tmp.dir;
         }

         for(int i = 0; i < linha; i++){
            System.out.print(tmp.elemento + " ");
            if(tmp.esq != null && tmp.inf != null){
               tmp = tmp.esq.inf;
            }
         }
         System.out.println();
      }
   }

    public static void main(String[] args){
      int casos = 0;

      casos = sc.nextInt();
      for(int i = 0; i < casos; i++){
         int linhas1 = sc.nextInt();
         int colunas1 = sc.nextInt();
         matriz m1 = new matriz(linhas1, colunas1);
         m1.lerDados();
         int linhas2 = sc.nextInt();
         int colunas2 = sc.nextInt();
         matriz m2 = new matriz(linhas2, colunas2);
         m2.lerDados();
         m1.DiagonalP();
         m1.DiagonalS();
         matriz soma = m1.soma(m2);
         soma.Exibir();
         matriz multiplicacao = m1.multiplicacao(m2);
         multiplicacao.Exibir();
      }
      sc.close();
   }

}