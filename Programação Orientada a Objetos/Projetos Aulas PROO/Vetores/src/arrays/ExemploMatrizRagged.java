package arrays;

import java.util.Scanner;

public class ExemploMatrizRagged {
    public static void main(String [] args){
        Scanner teclado = new Scanner(System.in);
        int [][] ragged = new int[3][];
        // definir quantidades de colunas diferentes
        ragged[0] = new int[4];
        ragged[1] = new int[2];
        ragged[2] = new int[3];
        
        // leitura dos dados
        for(int i = 0; i < ragged.length; i++){
            for(int j = 0; j < ragged[i].length; j++){
                System.out.print("(" + i + "," + j + "): ");
                ragged[i][j] = teclado.nextInt();
            }
        }
        
        // apresentar os dados usando for enhanced
        for(int[] linha : ragged){
            for(int celula : linha){
                System.out.print(celula + " ");
            }
            System.out.println();
        }
        
        for(int i = 0; i < ragged.length; i++){
            int [] linha = ragged[i];
            for(int j = 0; j < linha.length; j++){
                int celula = ragged[i][j];
                 System.out.print(celula + " ");
            }
            System.out.println();
        }
        
    }
}
