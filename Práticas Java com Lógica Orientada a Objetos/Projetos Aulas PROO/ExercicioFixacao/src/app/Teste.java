package app;

public class Teste {
    public static void main(String [] args){
        Aluno a1 = new Aluno();
        Aluno a2 = new Aluno();
        Professor p1 = new Professor();
        
        a1.nome = "Ana";
        a1.bv = "123";
        
        a2.nome = "Marcio";
        a2.bv = "456";
        
        p1.nome = "Gabriel";
        p1.disciplina = "poo";
        
        
        a1.assistirAula(p1);
        a2.assistirAula(p1);
        
    }
}
