using System;

class Program{
    static int calcular_idade(int A, int B, int M){
        int soma = 0;
        int C = 0, MaisVelho = 0; 

        soma = A + B;
        C = M - soma;

        if(A > B && A > C){
            MaisVelho = A;
        } else if(B > C){
            MaisVelho = B;
        } else{
            MaisVelho = C;
        }

        return MaisVelho;
    }

    static void Main(string[] args){
        int M = 0, A = 0, B = 0;

        do{
            M = int.Parse(Console.ReadLine());
        } while(M < 40 || M > 110);

        do{
            A = int.Parse(Console.ReadLine());
        } while(A < 1 || A > M);

        do{
            B = int.Parse(Console.ReadLine());
        } while(B < 1 || B > M);

        Console.Write("" + calcular_idade(A, B, M));
    }
}