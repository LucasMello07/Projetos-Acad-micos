package exemplo01;

import java.util.Objects;

public class Funcionario {

    private String nome;
    private double salario;

    // construtor padrão
    public Funcionario() {
        this("Desconhecido", 1000);
    }

    // construtor não-padrão
    public Funcionario(String nome) {
        // null.toUpperCase()==> problema!
        
        // soluções alternativas a partir Java 9
        //Objects.requireNonNull(nome, "O nome não pode ser nulo.");
        nome = Objects.requireNonNullElse(nome, "desconhecido");
        this.nome = nome.toUpperCase();
        
//        solução tradicional        
//        if (nome == null) {
//            this.nome = "DESCONHECIDO";
//        } else {
//            this.nome = nome.toUpperCase();
//        }
    }

    // construtor não-padrão
    public Funcionario(String nome,
            double salario) {
        // chama o construtor não-padrão com 1 parametro
        this(nome);
        this.salario = salario;
    }

    public String getNome() {
        return nome;
    }

    public double getSalario() {
        return salario;
    }

    // aumentarSalario(Funcionario f, double porcentagem)
    // f => parametro implicito (this!)
    // porcentagem => parametro explicito
    public void aumentarSalario(double porcentagem) {
        double taxa = porcentagem / 100.0;
        double aumento = this.salario * taxa;
        this.salario = this.salario + aumento;
    }

}
