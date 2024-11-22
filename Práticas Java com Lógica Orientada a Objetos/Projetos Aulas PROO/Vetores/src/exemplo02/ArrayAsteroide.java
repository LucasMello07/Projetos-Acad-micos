package exemplo02;

public class ArrayAsteroide {
    public static void main(String [] args){
        // cria array de objetos Asteroide
        Asteroide [] arrayAsteroides =
                new Asteroide[5];
        
        // crio o objeto e coloco na posição 0
        arrayAsteroides[0] = new Asteroide(10, 200);
        
        Asteroide a = new Asteroide(20, 400);
        arrayAsteroides[1] = a;
        
        System.out.println("A velocidade e: "+
                arrayAsteroides[0].getVelocidade());
        
    }
}
