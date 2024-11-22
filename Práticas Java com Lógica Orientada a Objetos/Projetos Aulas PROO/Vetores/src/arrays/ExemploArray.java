package arrays;

import java.util.Scanner;

public class ExemploArray {

    public static void main(String[] args) {
        Scanner teclado = new Scanner(System.in);
        int[] idades = new int[5];
        // int [] idades = {10, 20, 30};
        //idades[5] = 10; // ArrayIndexOutOfBounds

        // leitura do array
        // length guarda o tamanho do array
        for (int i = 0; i < idades.length; i++) {
            System.out.print("Digite uma idade: ");
            idades[i] = teclado.nextInt();
        }
        
        // visualizar os dados do array
        for(int i = 0; i < idades.length; i++){
            int idade = idades[i];
            System.out.println(idade);
        }
        
        // for enhanced ("for melhorado")
        for(int idade : idades){
            System.out.println(idade);
        }

    }
}
