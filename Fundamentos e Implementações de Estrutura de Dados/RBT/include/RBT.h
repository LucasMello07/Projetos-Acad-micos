#pragma once

#include <stdbool.h>

typedef enum RBTColor {
    RBT_COLOR_RED,
    RBT_COLOR_BLACK
} RBTColor;

typedef struct RBTNode {
    int key;
    struct RBTNode* left;
    struct RBTNode* right;
    RBTColor color;
    int rank;
    int level;
    int blackLevel;
} RBTNode;

typedef struct RBT {
    RBTNode* root;
    int size;
} RBT;

RBT* newRBT();
void rbtPut( RBT* abb, int key );
RBTNode* rbtPutR( RBTNode* node, int key );

RBTNode* rbtRotateLeft( RBTNode *node );
RBTNode* rbtRotateRight( RBTNode *node );
void rbtFlipColors( RBTNode *node );
bool rbtIsRed( RBTNode *node );

void rbtPreOrder( RBTNode* node );
void rbtInOrder( RBTNode* node );
void rbtPostOrder( RBTNode* node );

void rbtProcess( RBTNode* node, int* currentRank, int level, int* redNodeCount, int *maxBlackLevel );
void rbtDraw( RBT *rbt );

void rbtPrintNode( RBTNode *node );
void PercorrerRBT(RBTNode *no);