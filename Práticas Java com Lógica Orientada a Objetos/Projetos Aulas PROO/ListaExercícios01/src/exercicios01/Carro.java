package exercicios01;

public class Carro {
    
    private String marca;
    private String modelo;
    private int anoFabricacao;
    
    public String getMarca(){
       return marca;
    }
    public String getModelo(){
       return modelo;
    }
    public int getAnoFabricacao(){
       return anoFabricacao;
    }
    public void setMarca(String marca){
       this.marca = marca;
    }
    public void setModelo(String modelo){
       this.modelo = modelo;
    }
    public void setAnoFabricacao(int anoFabricacao){
       this.anoFabricacao = anoFabricacao;
    }
    public int calcularIdade(){
        return 2023-anoFabricacao;
    }
}
