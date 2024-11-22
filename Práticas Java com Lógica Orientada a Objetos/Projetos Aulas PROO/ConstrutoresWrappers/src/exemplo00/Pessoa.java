package exemplo00;

public class Pessoa {
    private String nome;
    private int idade;
    
    // construtor padrão
    public Pessoa(){
        idade = 0;
    }
    
    // construtor não-padrão
    public Pessoa(String nome) {
        this.nome = nome;
    }
    
    // construtor não-padrão
    public Pessoa(String nome, int idade){
        this(nome); // invoca o construtor não-padrão
        this.idade = idade;
    }
    
    // construtor não-padrão cópia
    public Pessoa(Pessoa outra){
        this.nome = outra.nome;
        this.idade = outra.idade;
    }
    
    public int getIdade(){
        return idade;
    }
    
    public String getNome(){
        return nome;
    }
    
    public void setNome(String nome){
        this.nome = nome;
    }
}
