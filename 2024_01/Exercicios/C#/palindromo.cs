using System;

class Program{
    static bool Palindromo(String str){
        int i = 0;
        int j = str.Length - 1;

        while(i < j){

            if (str[i] != str[j]){
                return false;
            }

            i++;
            j--;
        }

        return true;
    }

    static void Main(string[] args){
        string line;

        while((line = Console.ReadLine()) != "FIM"){
            if(Palindromo(line)){
                Console.WriteLine("SIM");
            } else{
                Console.WriteLine("NAO");
            }
        }
    }
}