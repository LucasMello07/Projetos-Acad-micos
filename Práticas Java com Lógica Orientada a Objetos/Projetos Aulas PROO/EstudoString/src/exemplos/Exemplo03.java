package exemplos;

public class Exemplo03 {
   public static void main(String [] args){
       String texto = "   São João   ";
       
       System.out.println(texto+
               "; Tamanho = "+
               texto.length());
       
       String trimTexto = texto.trim();
       
       System.out.println(trimTexto +
               "; Tamanho = "+
               trimTexto.length());
       
       String novoTexto = "São João da Boa Vista";
       String pedaco = novoTexto.substring(5);
       String pedaco2 = novoTexto.substring(5, 10);
       System.out.println(pedaco);
       System.out.println(pedaco2);
   } 
}
