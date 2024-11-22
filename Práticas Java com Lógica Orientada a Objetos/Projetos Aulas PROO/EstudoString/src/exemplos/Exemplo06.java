package exemplos;

public class Exemplo06 {
    
    // método de exemplo
    // retorna a string de um objeto StringBuilder
    public static String exibeMensagem(String nome){
        StringBuilder mensagem = new StringBuilder();
        mensagem.append("Olá, ");
        mensagem.append(nome);
        
        return mensagem.toString();
    }
    
    
    public static void main(String [] args){
        // 3 strings (texto, "Olá, " e "IFSP")
        //String texto = "Olá, " + "IFSP";
        
        // exemplo que em uma nova string é gerada
        //String novo = texto.replace('-', '!');
        StringBuilder  texto = new StringBuilder();
        texto.append("Olá, ");
        texto.append("IFSP");
        
        // imprime um objeto StringBuilder
        System.out.println(texto);
        
        // invoca método para observar uso do toString
        System.out.println(exibeMensagem("Ace"));
        
        System.out.println(texto.insert(3, "XXX").toString());
        
        //System.out.println(texto.reverse());
        
        System.out.println(texto.charAt(0));
        
        // obtém o caracter na posicao 0
        int letra = (int) texto.charAt(0);
        letra += 32;
        
        System.out.println("Letra = " + ((char)letra));
    }
}
