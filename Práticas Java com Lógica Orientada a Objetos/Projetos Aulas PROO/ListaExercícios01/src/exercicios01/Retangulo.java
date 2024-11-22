package exercicios01;

public class Retangulo {
    private int comprimento;
    private int largura;
    
    public int getComprimento(){
       return comprimento;
    }
    public void setComprimento(int comprimento){
       this.comprimento = comprimento;
   }
    public int getLargura(){
       return largura;
    }
    public void setLargura(int largura){
       this.largura = largura;
   }
    public double calcularArea(){
        return comprimento*largura;
    }
}
