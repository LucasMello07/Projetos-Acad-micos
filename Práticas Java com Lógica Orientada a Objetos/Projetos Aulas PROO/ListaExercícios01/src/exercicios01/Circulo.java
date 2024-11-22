
package exercicios01;

public class Circulo {
    private double raio;
    
    public double getRaio(){
       return raio;
    }
    public void setRaio(int raio){
       this.raio = raio;
   }
   public double calcularPerimetro(){
       return 2*(3.14)*(raio);
    }
}
