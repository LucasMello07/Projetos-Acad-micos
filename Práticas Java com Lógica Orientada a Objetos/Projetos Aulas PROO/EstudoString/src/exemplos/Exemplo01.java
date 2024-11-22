package exemplos;

public class Exemplo01 {
    public static void main(String [] args){
        String nome1 = "ana";
        String nome2 = "ana";
        
        String nome3 = new String("Ana");
        
        // o operador == não é apropriado,
        // pois ele não avalia o conteúdo do objeto
        // apontado pela variável de instância
        System.out.println("Usando == :"+
                (nome1 == nome3));
        
        System.out.println("Usando equals: " +
                nome1.equals(nome3));
        
        System.out.println("Usando equalsIgnoreCase: "+
                nome1.equalsIgnoreCase(nome3));
        
        
        
    }
}
