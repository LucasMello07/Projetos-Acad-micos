/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package esdc4aula07;

import static jdk.internal.vm.ThreadContainers.root;

/**
 * Ordenação usando árvore binária de busca.
 * 
 * @author Prof. Dr. David Buzatto
 */
public class BinarySearchTreeSort {

    public static <Type extends Comparable<Type>> void sort( Type[] array ) {
    private Node root;

    private class Node {
        int key;
        Node left, right;

        public Node(int item) {
            key = item;
            left = right = null;
        }
    }

    public void insert(int key) {
        root = insertRec(root, key);
    }

    private Node insertRec(Node root, int key) {
        if (root == null) {
            return new Node(key);
        }
        if (key < root.key) {
            root.left = insertRec(root.left, key);
        } else if (key > root.key) {
            root.right = insertRec(root.right, key);
        }
        return root;
    }

    public void inorder() {
        inorderRec(root);
    }

    private void inorderRec(Node root) {
        if (root != null) {
            inorderRec(root.left);
            System.out.println(root.key);
            inorderRec(root.right);
        }
      
        
    }
    
}
