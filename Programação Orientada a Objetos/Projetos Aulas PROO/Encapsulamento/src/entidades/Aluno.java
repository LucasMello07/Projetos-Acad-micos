package entidades;

public class Aluno {

    private String nome;
    private String ultimoNome;
    private int idade;
    
    // construtor não-padrão
    public Aluno(int valor){
        idade = valor;
    }
    
    // construtor padrão
    public Aluno(){}
    
    
    // interface pública
    // tarefas específicas
    public void alterarNome(String nome){
        String [] nomes = nome.split(" ");
        this.nome = nomes[0];
        // TODO: reunir todos os elementos
        if (nomes.length > 1) {
            this.ultimoNome = nomes[1];
        }
    }
    
    public void alterarIdade(int valor) {
        if (valor > 0) {
            idade = valor;
        }
    }
    
    public int qualSuaIdade(){
        return idade;
    }
    
    public String qualSeuNome(){
        return nome + " " + ultimoNome;
    }
    
    public String qualSeuPrimeiroNome(){
        return nome;
    }
    
    public String qualSeuUltimoNome() {
        return ultimoNome;
    }

}
