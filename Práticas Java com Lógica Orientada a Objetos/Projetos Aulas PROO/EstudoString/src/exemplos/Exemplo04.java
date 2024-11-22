package exemplos;

public class Exemplo04 {
    public static void main(String [] args){
        String cidade = "São João da Boa Vista";
        String [] palavras = cidade.split(" ");
        System.out.println("Tamanho = "+ palavras.length);
        
        for(String p : palavras){
            System.out.println(p);
        }
        
        String novaCidade = cidade.replace(' ', '-');
        System.out.println(novaCidade);
        
        // neste caso teria o mesmo resultado de split(" ")
        //String [] novasPalavras = novaCidade.split("-");
    }
}
