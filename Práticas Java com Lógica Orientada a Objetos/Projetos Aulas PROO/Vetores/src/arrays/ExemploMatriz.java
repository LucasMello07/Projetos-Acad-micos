package arrays;

import java.util.Scanner;

public class ExemploMatriz {

    public static void main(String[] args) {
        Scanner teclado = new Scanner(System.in);
        int[][] matriz = new int[2][3];

        for (int i = 0; i < matriz.length; i++) {
            for (int j = 0; j < matriz[0].length; j++) {
                System.out.print("(" + i + "," + j + "): ");
                matriz[i][j] = teclado.nextInt();
            }
        }
        
        // visualizar
        for(int i = 0; i < matriz.length; i++){
            for(int j = 0; j < matriz[0].length; j++){
                System.out.print(matriz[i][j] + " ");
            }
            System.out.println();
        }
    }
}
