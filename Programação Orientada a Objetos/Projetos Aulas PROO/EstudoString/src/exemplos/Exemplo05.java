package exemplos;

import java.util.Arrays;

public class Exemplo05 {
    public static void main(String [] args){
        String cidade = "   São  João     da  Boa Vista";
        String [] palavras = cidade.trim().split("\\s+");
        
        System.out.println(Arrays.toString(palavras));
    }
}
