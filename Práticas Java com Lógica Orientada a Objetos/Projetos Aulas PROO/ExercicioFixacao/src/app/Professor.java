package app;

public class Professor {
    String nome;
    String disciplina;
    
    String ministrar(){
        String mensagem = "O professor "+
                nome + " da disciplina "+
                disciplina + " passou conteúdo.";
        return mensagem;
    }
}
