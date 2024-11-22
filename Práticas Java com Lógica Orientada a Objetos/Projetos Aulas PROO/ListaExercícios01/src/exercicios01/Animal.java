
package exercicios01;


public class Animal {
    private String especie;
    private int idade;
    private double peso;
    
    public int getIdade(){
       return idade;
   }
    public void setIdade(int idade){
       this.idade = idade;
   }
    public double getPeso(){
       return peso;
   }
    public void setPeso(int peso){
       this.peso = peso;
   }
    public String getEspecie(){
       return especie;
   }
    public void setEspecie(String especie){
       this.especie = especie;
   }
   public boolean isAcimaPesoIdeal(){
       return (peso > ((1/10)*(idade*12)));
   }
}
