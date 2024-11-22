package entidades;

public class Roda {

    // atributos (características)
    private String material;
    private double diametro;
    private String marca;

    // métodos (comportamentos)
    public void alterarMaterial(String material) {
        this.material = material;
    }

    public String qualMaterial() {
        return material;
    }

    public void alterarDiamero(double diametro) {
        if (diametro > 0) {
            this.diametro = diametro;
        }
    }
    
    

    public double qualDiametro() {
        return diametro;
    }

    public void alterarMarca(String marca) {
        this.marca = marca;
    }

    public String qualMarca() {
        return marca;
    }

    public void girar() {
        System.out.println("roda girando...");
    }

}
