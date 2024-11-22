package app;

public class Aluno {
    String nome;
    String bv;
    
    void assistirAula(Professor p){
        
        String mensagem = "O aluno(a) " +
                nome + " assistiu a aula." +
                "Conteudo: " + p.ministrar();
        
        
        System.out.println( mensagem );
    }
}
