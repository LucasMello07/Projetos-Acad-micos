package entidades;

public class Moto {
    private Motor motor;
    private Roda rodaDianteira;
    private Roda rodaTraseira;
    
    public void alterarMotor(Motor motor){
        this.motor = motor;
    }
    
    public Motor qualMotor(){
        return motor;
    }
    
    public void alterarRodaDianteira(Roda roda){
        rodaDianteira = roda;
    }
    
    public Roda qualRodaDianteira(){
        return rodaDianteira;
    }
    
    public void alterarRodaTraseira(Roda roda){
        rodaTraseira = roda;
    }
    
    public Roda qualRodaTraseira(){
        return rodaTraseira;
    }
    
    public void ligar(){
        System.out.println("Ligando a moto...");
        motor.realizarIgnicao();
        System.out.println("Vrum...Vrum...");
    }
    
    public void acelerar(){
        System.out.println("acelerando...");
    }
    
    public void frear(){
       System.out.println("freou..."); 
    }
}
