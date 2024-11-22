package exemplo02;

public class Asteroide {
    private double diametro;
    private double velocidade;
    
    public Asteroide(double diametro, double velocidade){
        this.diametro = diametro;
        this.velocidade = velocidade;
    }
    
    public double getDiametro(){
        return diametro;
    }
    
    public double getVelocidade(){
        return velocidade;
    }
}
