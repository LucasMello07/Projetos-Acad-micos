/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package esdc4aula10;

import aesd.ds.interfaces.PriorityQueue;
import java.util.Iterator;
import java.util.NoSuchElementException;

/**
 * Implementação de uma fila de prioridades máxima usando um heap d-ário máximo.
 * 
 * Critério de ordenação:
 *     - MaxHeap:
 *         * Chave do elemento pai sempre maior ou igual aos filhos
 *     – Chaves armazenadas em um array.
 *
 * Construção:
 *     – Heap d-ário (até d filhos)
 *     – Completa: elementos sem filhos apenas no último nível
 *      (e anterior, quando o último nível não está completo)
 *
 * Árvore d-ária completa:
 *     – Armazenamento direto em array!
 *     - Raiz na posição 1
 *     - Último elemento na posição tamanho do array - 1
 *     – Manipulação dos índices: ?
 *
 * Elemento violando a condição heap máximo
 *     – Chave maior que a chave do pai
 *        * O elemento precisa "subir" na árvore
 *        * Bottom-Up heapify (swim => flutuar)
 *     – Chave menor que a chave dos filhos (um ou dois)
 *        * O elemento precisa "descer" na árvore
 *        * Top-Down heapify (sink => afundar)
 *
 *
 * @param <Key> Tipo das chaves que serão armazenadas na fila de prioridades.
 *
 * @author Prof. Dr. David Buzatto
 */
public class DAryMaxPriorityQueue<Key extends Comparable<Key>> implements PriorityQueue<Key> {

    private Key[] pq;
    
    private int n;
    
    private int d;

    public DAryMaxPriorityQueue() {
        this( 1, 2 );
    }
    
    public DAryMaxPriorityQueue( int d ) throws IllegalArgumentException {
        this( 1, d );
        
    }
    
    @SuppressWarnings( "unchecked" )
    public DAryMaxPriorityQueue( int initCapacity, int d ) throws IllegalArgumentException {
        
        if ( d < 2 ) {
            throw new IllegalArgumentException( 
                    "the heap arity must be greater than or equal to 2" );
        }
        
        pq = (Key[]) new Comparable[initCapacity + 1];
        this.d = d;
        
    }

    @SuppressWarnings( "unchecked" )
    private void resize( int capacity ) {
        
        Key[] temp = (Key[]) new Comparable[capacity];
        
        for ( int i = 1; i <= n; i++ ) {
            temp[i] = pq[i];
        }
        
        pq = temp;
        
    }

    @Override
    public void insert( Key key ) {

        
        if ( n == pq.length - 1 ) {
            resize( d * pq.length );
        }

        
        pq[++n] = key;
        swim( n );
        
    }
    
    @Override
    public Key peek() throws NoSuchElementException {
        
        if ( isEmpty() ) {
            throw new NoSuchElementException( "Priority queue underflow" );
        }
        
        return pq[1];
        
    }
    
    @Override
    public Key delete() throws NoSuchElementException {
        
        if ( isEmpty() ) {
            throw new NoSuchElementException( "Priority queue underflow" );
        }
        
        Key max = pq[1];
          
        exchange( 1, n-- );
        
       
        sink( 1 );
        
        pq[n + 1] = null;  
        
        if ( ( n > 0 ) && ( n == ( pq.length - 1 ) / 4 ) ) {
            // diminui a capacidade pela metade
            resize( pq.length / 2 );
        }
        
        return max;
        
    }
    
    private void swim( int k ) {
        while (k > 1 && less((k+d-2)/d, k)){
            exchange(k, (k+d-2)/d);
            k = (k+d-2)/d;
        }
    }

    private void sink( int k ) {
       while (((k-1)*d)+2 <= n){
            int j = ((k-1)*d)+2;
            
            for (int i=j+1; i <= n; i++){
                if (j < n && less(j,i)){
                    j = i;
                }
            }
            
            if (!less(k,j)){
                break;
            }
            exchange(k, j);
            k = j;
        }
    }

    
    private int dAryParent( int k ) {
        return k;
    }
    
    
    private int dAryFirstChild( int k ) {
        return k;
    }
    
    
    private boolean less( int i, int j ) {
        return pq[i].compareTo( pq[j] ) < 0;
    }

    
    private void exchange( int i, int j ) {
        Key temp = pq[i];
        pq[i] = pq[j];
        pq[j] = temp;
    }
    
    
    @Override
    public void clear() {
        for ( int i = 0; i < pq.length; i++ ) {
            pq[i] = null;
        }
        n = 0;
    }
    
    
    @Override
    public boolean isEmpty() {
        return n == 0;
    }
    
    @Override
    public int getSize() {
        return n;
    }
    
    @Override
    public Iterator<Key> iterator() {
        return new HeapIterator();
    }

    private class HeapIterator implements Iterator<Key> {

        private DAryMaxPriorityQueue<Key> copy;

        public HeapIterator() {
            copy = new DAryMaxPriorityQueue<>( getSize() );
            for ( int i = 1; i <= n; i++ ) {
                copy.insert( pq[i] );
            }
        }

        @Override
        public boolean hasNext() {
            return !copy.isEmpty();
        }
        
        @Override
        public Key next() {
            if ( !hasNext() ) {
                throw new NoSuchElementException();
            }
            return copy.delete();
        }
        
        @Override
        public void remove() {
            throw new UnsupportedOperationException();
        }
        
    }
    
    
    @Override
    public String toString() {
        
        StringBuilder sb = new StringBuilder();
        
        if ( !isEmpty()) {
            
            
            preOrder( 1, "", sb );
            
        } 
        
        else {
            sb.append( "empty max priority queue!\n" );
        }
        
        return sb.toString();
        
    }
    
    private void preOrder( int i, String ident, StringBuilder sb ) {
        
        if ( i <= n && pq[i] != null ) {

            String rootIdent = "";
            String leafIdent = "";

            
            if ( i != 1 ) {
                rootIdent = ident + "|--";
                leafIdent = ident + "|  ";
            }

            
            sb.append( rootIdent );
            sb.append( pq[i] );
            
            
            if ( i == 1 ) {
                sb.append(  " <- max (root)" );
            }
            sb.append( "\n" );

            
            int start = dAryFirstChild( i );

            
            for ( int j = start; j < start + d; j++ ) {
                preOrder( j, leafIdent, sb );
            }

        }
        
    }

}
