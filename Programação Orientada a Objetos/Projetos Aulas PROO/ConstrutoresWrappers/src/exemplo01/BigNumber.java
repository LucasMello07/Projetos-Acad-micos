package exemplo01;

import java.math.BigDecimal;

public class BigNumber {
    public static void main(String [] args){
        // formata a saída e não ajusta o valor
        //System.out.printf("%.2f\n", (2.0 - 1.1) );
        
        System.out.println( (2.0 - 1.1) );
        
        BigDecimal num1 = BigDecimal.valueOf(2.0);
        BigDecimal num2 = BigDecimal.valueOf(1.1);
        
        BigDecimal resultado = num1.subtract(num2);
        System.out.println(resultado);
    }
}
