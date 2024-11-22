/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package carroUML;

/**
 *
 * @author Samuel
 */

/*2. (30,00) Um carro é formado por quatro rodas e possui um modelo (standard, luxo). Cada
roda possui um diâmetro (aro) e uma pressão de calibragem. Além disso, o automóvel – em
estudo – possui três portas. Cada porta é caracterizada pela dimensão e posição (esquerdo,
direito, traseiro). Um carro possui bancos que são caracterizados pela dimensão e cor do
assento. Por fim, o automóvel conta ainda com um volante – que pode ser normal,
hidráulico ou elétrico – e com o câmbio de marchas que pode ter cinco ou seis marchas
dependendo do seu modelo. Elabore um diagrama de classes a partir do problema
apresentado e represente as classes e os relacionamentos entre elas. Crie um projeto no
Netbeans e implemente o diagrama de classe elaborado.
*/
public class Carro {
    
    public Rodas r1 = new Rodas();
    public Rodas r2 = new Rodas();
    public Rodas r3 = new Rodas();
    public Rodas r4 = new Rodas();
    public Bancos b1 = new Bancos();   
    public Volante v1 = new Volante();
    public Cambio c = new Cambio();
    public Portas p1 = new Portas();
    public Portas p2 = new Portas();
    public Portas p3 = new Portas();
    
    
    public void ignicao(){
        System.out.println("O carro esta ligado.");
    }
    
    public void desligar(){
        System.out.println("O carro esta desligado.");
    }
    
    
    
    
}
