package entidades;

public class TesteLivro {

    public static void main(String[] args) {
        Livro livro1 = new Livro();
        Livro livro2 = new Livro();

        livro1.titulo = "Meditações";
        livro1.autor = "Marco Aurélio";
        livro1.editora = "Intrinseca";
        livro1.folhear();

        livro2.titulo = "Amor de redenção";
        livro2.autor = "Francine";
        livro2.editora = "Pontes";
        livro2.folhear();
        livro2.folhear();

//        System.out.println("Eu, " + livro1.titulo
//                + " estou na página " + livro1.paginaAtual);
//
//        System.out.println("Eu, " + livro2.titulo
//                + " estou na página " + livro2.paginaAtual);
        
        livro1.qualPaginaVoceEsta();
        livro2.qualPaginaVoceEsta();
    }
}
