package entidades;

public class TesteComplexo {
    public static void main(String [] args){
        // Tipo Abstrato de Dados (TAD)
        Complexo a = new Complexo();
        Complexo b = new Complexo();
        
        // a = 2 + 3j
        a.real = 2.0;
        a.imag = -3.0;
        a.converterParaTexto();
        
        // b = 3 + 5j
        b.real = 3.0;
        b.imag = 5.0;
        
        Complexo s = a.somar(b);
        System.out.println(a.converterParaTexto());
    }
}
