#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "raylib.h"
#include "RBT.h"

RBT* newRBT() {

    RBT* abb = (RBT*) malloc( sizeof( RBT ) );
    abb->root = NULL;
    abb->size = 0;

    return abb;

}

void rbtPut( RBT* rbt, int key ) {
    rbt->root = rbtPutR( rbt->root, key );
}

RBTNode* rbtPutR( RBTNode* node, int key ) {

    if ( node == NULL ) {

        RBTNode* newNode = (RBTNode*) malloc( sizeof(RBTNode) );
        newNode->left = NULL;
        newNode->right = NULL;
        newNode->key = key;
        newNode->color = RBT_COLOR_RED;
        newNode->rank = 0;
        newNode->level = 0;
        newNode->blackLevel = 0;

        return newNode;

    } else {
        if ( key < node->key ) {
            node->left = rbtPutR( node->left, key );
        } else if ( key > node->key ) {
            node->right = rbtPutR( node->right, key );
        } else {
            // value update if storing value
        }
    }

    if ( rbtIsRed( node->right ) && !rbtIsRed( node->left ) ) {
        node = rbtRotateLeft( node );
    }

    if ( rbtIsRed( node->left ) && rbtIsRed( node->left->left ) ) {
        node = rbtRotateRight( node );
    }

    if ( rbtIsRed( node->left ) && rbtIsRed( node->right ) ) {
        rbtFlipColors( node );
    }

    return node;

}

RBTNode* rbtRotateLeft( RBTNode *node ) {

    RBTNode *temp = node->right;
    node->right = temp->left;
    temp->left = node;
    temp->color = node->color;
    node->color = RBT_COLOR_RED;

    return temp;

}

RBTNode* rbtRotateRight( RBTNode *node ) {

    RBTNode *temp = node->left;
    node->left = temp->right;
    temp->right = node;
    temp->color = node->color;
    node->color = RBT_COLOR_RED;

    return temp;

}

void rbtFlipColors( RBTNode *node ) {
    node->color = RBT_COLOR_RED;
    node->left->color = RBT_COLOR_BLACK;
    node->right->color = RBT_COLOR_BLACK;
}

bool rbtIsRed( RBTNode *node ) {
    if ( node == NULL ) {
        return false;
    }
    return node->color == RBT_COLOR_RED;
}

void rbtPreOrder( RBTNode* node ) {
    if ( node != NULL ) {
        rbtPrintNode( node );
        rbtPreOrder( node->left );
        rbtPreOrder( node->right );
    }
}

void rbtInOrder( RBTNode* node ) {
    if ( node != NULL ) {
        rbtInOrder( node->left );
        rbtPrintNode( node );
        rbtInOrder( node->right );
    }
}

void rbtPostOrder( RBTNode* node ) {
    if ( node != NULL ) {
        rbtPostOrder( node->left );
        rbtPostOrder( node->right );
        rbtPrintNode( node );
    }
}

void rbtProcess( RBTNode* node, int* currentRank, int level, int *redNodeCount, int *maxBlackLevel ) {
    if ( node != NULL ) {

        if ( node->color == RBT_COLOR_RED ) {
            (*redNodeCount)++;
        }

        rbtProcess( node->left, currentRank, level + 1, redNodeCount, maxBlackLevel );
        node->rank = *currentRank;
        node->level = level;
        node->blackLevel = level - *redNodeCount;
        (*currentRank)++;
        rbtProcess( node->right, currentRank, level + 1, redNodeCount, maxBlackLevel );

        if ( node->color == RBT_COLOR_RED ) {
            (*redNodeCount)--;
        }

        if ( *maxBlackLevel < node->blackLevel ) {
            *maxBlackLevel = node->blackLevel;
        }

    }
}

void rbtDraw( RBT *rbt ) {
    // desenhe a árvore vermelho e preto aqui
}

void rbtPrintNode( RBTNode *node ) {
    printf( "%d %c (%d/%d) ", 
            node->key, 
            node->color == RBT_COLOR_RED ? 'R' : 'B',
            node->rank, 
            node->level );
}