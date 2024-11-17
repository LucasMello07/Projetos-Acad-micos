
package exercicios01;

public class Livro {
   private String titulo;
   private String autor;
   private int numeroPaginas;
   
   public String getTitulo(){
       return titulo;
    }
   public String getAutor(){
       return autor;
    }
   public int getNumeroPaginas(){
       return numeroPaginas;
   }
   public void setTitulo(String titulo){
       this.titulo = titulo;
    }
   public void setAutor(String autor){
       this.autor = autor;
    }
   public void setNumeroPaginas(int numeroPaginas){
       this.numeroPaginas = numeroPaginas;
    }
   public boolean isGrande(){
       return numeroPaginas > 100;
   }
}
