package arrays;

import java.util.Random;

public class Aleatorio {
    public static void main(String [] args){
        Random r = new Random(System.currentTimeMillis());
        
        System.out.println(r.nextDouble(1000.0));
    }
}
