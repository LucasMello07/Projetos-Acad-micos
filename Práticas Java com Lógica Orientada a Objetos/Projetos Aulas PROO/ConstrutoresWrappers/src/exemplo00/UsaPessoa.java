package exemplo00;

public class UsaPessoa {
    public static void main(String [] args){
        Pessoa p = new Pessoa("Clóvis");
        Pessoa p2 = p;
        
        System.out.println("p: " + p.getNome());
        System.out.println("p2:" + p2.getNome());
        //System.out.println(p);
        //System.out.println(p2);
        
        System.out.println("p == p2? "+
                (p2 == p));
        
        p2.setNome("Clodoaldo");
        System.out.println(p.getNome());
    }
}
