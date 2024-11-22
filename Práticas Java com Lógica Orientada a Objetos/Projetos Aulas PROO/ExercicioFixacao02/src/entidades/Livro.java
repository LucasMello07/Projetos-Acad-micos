package entidades;

public class Livro {
    // atributos    
    String titulo;
    String autor;
    String editora;
    int paginaAtual;
    
    // métodos
    void folhear(){
        paginaAtual++;
    }
    
    void qualPaginaVoceEsta(){
        System.out.println("Eu, " + titulo +                
                " estou na página " + paginaAtual);
    }
}
