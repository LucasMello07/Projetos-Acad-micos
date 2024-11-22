package exemplo01;

public class UsaFuncionario {

    public static void exibir(Funcionario f) {
        System.out.println(f.getNome()
                + "\n" + f.getSalario()
                + "\n==========");
    }

    public static void main(String[] args) {
        Funcionario f1 = new Funcionario();
        Funcionario f2 = new Funcionario("Guilherme", 3000);
        String nome = null;
        Funcionario f3 = new Funcionario(nome);
        exibir(f3);

        exibir(f1);
        
        // aumenta o salario em 5%
        f2.aumentarSalario(5);
        
        exibir(f2);
    }
}
