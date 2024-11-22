
package com.mycompany.almoxarifado;

import java.util.Random;

/**
 *
 * @author Adilson JR,Lucas Mello,Viktor Blasck,Otavio Henrique.
 */
public class Vendedor implements Runnable{
    private String nome;
    private Almoxarifado almoxarifado;

    public Vendedor(String nome, Almoxarifado almoxarifado) {
        this.nome = nome;
        this.almoxarifado = almoxarifado;
    }
    @Override
    public void run() {
        try {
            while (true) {
                almoxarifado.separarItem(nome);
                almoxarifado.coletarItem(nome);
                System.out.println(nome + " finalizou a coleta no almoxarifado.");
                Thread.sleep(new Random().nextInt(15000) + 5000); 
        } catch (InterruptedException e) {
            Thread.currentThread().interrupt();
        }
    }
    
}
