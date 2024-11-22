#pragma once

typedef struct No {
    int key;
    struct No* e;
    struct No* d;
    int rank;
    int level;
} No;

typedef struct ABB {
    No* raiz;
    int tamanho;
} ABB;

ABB* criarArvore();
void put( ABB* abb, int key );
No* putR( No* no, int key );

void preOrder( No* no );
void inOrder( No* no );
void postOrder( No* no );

void process( No* no, int* currentRank );