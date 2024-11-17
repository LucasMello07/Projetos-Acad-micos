package exemplo03;

import javax.swing.JOptionPane;

public class Wrappers {
    public static void main(String [] args){
        Integer valor = 10; // autoboxing
        
        System.out.println(
                Integer.toBinaryString(8));
        
        int idade = 0;
        String resposta =
                JOptionPane.showInputDialog("Qual sua idade?");
        
        idade = Integer.parseInt(resposta);
        
        System.out.println("Idade digitada foi "+ idade);
        
    }
}
