package entidades;

public class Motor {
    // atributos
    private String cilindradas;
    private int potencia;
    private int quantidadeLitros;
    private boolean eletrico;
    
    // métodos
    public void alterarCilindradas(String cilindradas){
        this.cilindradas = cilindradas;
    }
    
    public String qualCilindradas(){
        return cilindradas;                
    }
    
    public void setPotencia(int potencia){
        this.potencia = potencia;
    }
    
    public int getPotencia(){
        return potencia;
    }
    
    public void alterarQuantidadeLitros(int quantidade){
        this.quantidadeLitros = quantidade;
    }
    
    public int qualQuantidadeLitros(){
        return quantidadeLitros;
    }
    
    public void alterarEletrico(boolean status){
        eletrico = status;
    }
    
    public boolean ehEletrico(){
        return eletrico;
    }
    
    public void realizarIgnicao(){
        System.out.println("realizou ignição...");
    }
}
