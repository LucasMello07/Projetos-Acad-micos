#include <stdio.h>
#include <stdlib.h>
#include "ABB.h"

ABB* criarArvore() {

    ABB* abb = (ABB*) malloc( sizeof( ABB ) );
    abb->raiz = NULL;
    abb->tamanho = 0;

    return abb;

}

void put( ABB* abb, int key ) {
    abb->raiz = putR( abb->raiz, key );
}

No* putR( No* no, int key ) {



    if ( no == NULL ) {
        No* novoNo = (No*) malloc( sizeof(No) );
        novoNo->e = NULL;
        novoNo->d = NULL;
        novoNo->key = key;
        novoNo->rank = 0;
        novoNo->level = 0;
        return novoNo;
    } else {
        if ( key < no->key ) {
            no->e = putR( no->e, key );
        } else if ( key > no->key ) {
            no->d = putR( no->d, key );
        } else {
        }
    }

    return no;

}

void preOrder( No* no ) {
    if ( no != NULL ) {
        printf( "%d (%d/%d) ", no->key, no->rank, no->level );
        preOrder( no->e );
        preOrder( no->d );
    }
}

void inOrder( No* no ) {
    if ( no != NULL ) {
        inOrder( no->e );
        printf( "%d (%d/%d) ", no->key, no->rank, no->level );
        inOrder( no->d );
    }
}

void postOrder( No* no ) {
    if ( no != NULL ) {
        postOrder( no->e );
        postOrder( no->d );
        printf( "%d (%d/%d) ", no->key, no->rank, no->level );
    }
}

void process( No* no, int* currentRank ) {
    if ( no != NULL ) {
        process( no->e, currentRank );
        no->rank = *currentRank;
        (*currentRank)++;
        process( no->d, currentRank );
    }
}