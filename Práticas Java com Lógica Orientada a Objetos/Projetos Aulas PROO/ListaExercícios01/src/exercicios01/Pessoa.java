package exercicios01;

public class Pessoa {
   private String nome; 
   private int idade;
   private String telefone;
   
   public String getNome(){
       return nome;
   }
   public int getIdade(){
       return idade;
   }
   public String getTelefone(){
       return telefone;
   }
   
   public void setNome(String nome){
       this.nome = nome;
   }
   public void setIdade(int idade){
       this.idade = idade;
   }
   public void setTelefone(String telefone){
       this.telefone = telefone;
   }
   
   
}
