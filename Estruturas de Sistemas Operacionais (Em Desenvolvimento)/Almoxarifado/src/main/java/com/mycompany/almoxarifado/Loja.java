package com.mycompany.almoxarifado;

public class Loja {
    public static void main(String[] args) {
        Almoxarifado almoxarifado = new Almoxarifado();

        Vendedor vendedor1 = new Vendedor("Vendedor 1", almoxarifado);
        Vendedor vendedor2 = new Vendedor("Vendedor 2", almoxarifado);

        Thread thread1 = new Thread(vendedor1);
        Thread thread2 = new Thread(vendedor2);

        thread1.start();
        thread2.start();
    }
    
    
    
}
