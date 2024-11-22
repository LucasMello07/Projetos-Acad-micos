package exemplo02;

public class Jogo {
    public static void main(String [] args){
        //Estado e = Estado.PAPEL;
        Estado e = Estado.valueOf("TESOURA");
        
        System.out.println("Posição: "+ e.ordinal());
        System.out.println("Estado: "+ e);
        
        // Exemplo com a enumeração Dia
        Dia d = Dia.SEGUNDA;
        
        switch (d) {
            case SEGUNDA:
                System.out.println("Estuda");
                break;
            case TERÇA:
                System.out.println("Estuda");
                break;
            default:
                System.out.println("Estuda também");
        }
    }
}
