package entidades;

public class App {
    public static void main(String [] args){
        Motor m1 = new Motor();
        Roda r1 = new Roda();
        Roda r2 = new Roda();
        
        Moto motoca = new Moto();
        motoca.alterarMotor(m1);
        motoca.alterarRodaDianteira(r1);
        motoca.alterarRodaTraseira(r2);
        
        motoca.ligar();
        
        //motoca.alterarRodaDianteira(r2);
        //motoca.alterarRodaTraseira(r1);
    }
}
