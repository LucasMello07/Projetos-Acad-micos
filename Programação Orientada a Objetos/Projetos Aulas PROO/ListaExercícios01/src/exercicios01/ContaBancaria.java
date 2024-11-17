package exercicios01;


public class ContaBancaria {
   private String nomeTitular; 
   private double saldo;
   private int numeroConta;
   
   public double saldo(){
       return saldo;
   }
   public int getNumeroConta(){
       return numeroConta;
   }
   public String getNomeTitular(){
       return nomeTitular;
   }
   
   public void setNomeTitular(String nomeTitular){
       this.nomeTitular = nomeTitular;
   }
   public void depositar(double valor){
       if(valor > 0){
           saldo += valor;
       }
   }
   public void sacar(double valor){
       if(saldo >= valor){
           saldo -= valor;
        }else{
           System.out.println("Saldo de " + saldo());
       }
   }
   
}
