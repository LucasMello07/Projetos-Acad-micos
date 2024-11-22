#include <stdio.h>
#include <stdlib.h>
#include "raylib.h"
#include "BST.h"

BST* newBST() {

    BST* abb = (BST*) malloc( sizeof( BST ) );
    abb->root = NULL;
    abb->size = 0;

    return abb;

}

void bstPut( BST* abb, int key ) {
    abb->root = bstPutR( abb->root, key );
}

BSTNode* bstPutR( BSTNode* node, int key ) {

    if ( node == NULL ) {
        BSTNode* newNode = (BSTNode*) malloc( sizeof(BSTNode) );
        newNode->left = NULL;
        newNode->right = NULL;
        newNode->key = key;
        newNode->rank = 0;
        newNode->level = 0;
        return newNode;
    } else {
        if ( key < node->key ) {
            node->left = bstPutR( node->left, key );
        } else if ( key > node->key ) {
            node->right = bstPutR( node->right, key );
        } else {
            // value update if storing value
        }
    }

    return node;

}

void bstPreOrder( BSTNode* node ) {
    if ( node != NULL ) {
        bstPrintNode( node );
        bstPreOrder( node->left );
        bstPreOrder( node->right );
    }
}

void bstInOrder( BSTNode* node ) {
    if ( node != NULL ) {
        bstInOrder( node->left );
        bstPrintNode( node );
        bstInOrder( node->right );
    }
}

void bstPostOrder( BSTNode* node ) {
    if ( node != NULL ) {
        bstPostOrder( node->left );
        bstPostOrder( node->right );
        bstPrintNode( node );
    }
}

void bstProcess( BSTNode* node, int* currentRank, int level, int *maxLevel ) {
    if ( node != NULL ) {
        bstProcess( node->left, currentRank, level+1, maxLevel );
        node->rank = *currentRank;
        node->level = level;
        (*currentRank)++;
        bstProcess( node->right, currentRank, level+1, maxLevel );
        if ( *maxLevel < node->level ) {
            *maxLevel = node->level;
        }
    }
}

void percursoDesenho( BSTNode *no ){

    int margem = 120;

    DrawFPS( 640, 10 );


     if(no != NULL){
        DrawCircleLines(margem + 50 * no->rank, margem+ 50 * no->level,15.0,BLACK);                        
        if(no->left != NULL){
            DrawLine(margem + 50 * no->rank, margem + 50 * no->level, margem + no->left->rank * 50, margem + no->left->level * 50,BLACK);
        }
            
        if(no->right != NULL){
            DrawLine(margem + 50 * no->rank, margem + 50 * no->level,margem +  no->right->rank * 50,margem + no->right->level * 50,BLACK);
        }
            
        percursoDesenho(no->left); 
        percursoDesenho(no->right);
        DrawCircle(margem + 50 * no->rank, margem + 50 * no->level,14.8,WHITE); 
        DrawText( TextFormat( "%d", no->key) , margem + 50 * no->rank - 3.6, margem + 50 * no->level -6, 10, BLACK); 


    }
}
void bstDraw( BST *bst ) {
    // desenhe a árvore binária de busca aqui

    percursoDesenho( bst->root );


}



void bstPrintNode( BSTNode *node ) {
    printf( "%d (%d/%d) ", node->key, node->rank, node->level );
}