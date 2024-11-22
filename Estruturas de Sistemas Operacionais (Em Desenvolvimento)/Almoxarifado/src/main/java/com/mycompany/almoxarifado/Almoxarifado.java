package com.mycompany.almoxarifado;

import java.util.Random;
import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

public class Almoxarifado {

    private Lock lock = new ReentrantLock();
    private boolean itemSeparado = false;

    
    public void separarItem(String vendedor) throws InterruptedException {
        lock.lock();  
        try {
            System.out.println(vendedor + " solicitou uma roupa ao almoxarifado.");
            Thread.sleep(new Random().nextInt(9000) + 1000); 
            itemSeparado = true;
            System.out.println("Almoxarifado separou um item para " + vendedor);
            System.out.println("Local de separação carregado.");
            Thread.sleep(5000);  
        } finally {
            lock.unlock();
        }

    }

    public synchronized void coletarItem(String vendedor) throws InterruptedException {
        while (!itemSeparado) {
            wait();  
        }
        System.out.println(vendedor + " coletou o item no almoxarifado.");
        itemSeparado = false;
        notifyAll();  
    }
        
}
