package entidades;

public class Complexo {
    // atributos
    double real;
    double imag;
    
    // métodos
    Complexo somar(Complexo outro){
        Complexo c = new Complexo();
        
        // (real1 + real2) + (imag1 + imag2)j
        c.real = real + outro.real;
        c.imag = imag + outro.imag;
        
        return c;
    }
    
    String converterParaTexto(){
        String texto = real + " + " + imag +"j";
        return texto;
    }
}
