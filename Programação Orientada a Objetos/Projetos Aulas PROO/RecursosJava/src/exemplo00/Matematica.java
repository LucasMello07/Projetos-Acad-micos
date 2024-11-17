package exemplo00;

/*
Exemplo de métodos sobrecarregados
method overloading
 */
public class Matematica {
    
    public static void exibir(int valor){
        System.out.println(valor);
    }

    public int somar(int c, double d){
        return 0;
    }
    public int somar(int a, int b) {
        return (a + b);
    }

    // método sobrecarregado
    public int somar(int a, int b, int c) {
        return (a + b + c);
    }

    // método sobrecarregado
    public int somar(int[] vetor) {
        int resultado = 0;
        for (int i = 0; i < vetor.length; i++) {
            resultado = resultado + vetor[i];
        }
        return resultado;
    }
}
