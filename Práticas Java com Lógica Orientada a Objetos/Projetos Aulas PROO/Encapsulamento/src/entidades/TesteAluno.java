package entidades;

public class TesteAluno {

    public static void main(String[] args) {
        Aluno a = new Aluno();
        
        a.alterarNome("Márcio Andrade");

        a.alterarIdade(20);
        
        System.out.println(a.qualSuaIdade());
        System.out.println(a.qualSeuUltimoNome());
    }
}
