/**
 * @file GameWorld.h
 * @author Prof. Dr. David Buzatto
 * @brief GameWorld implementation.
 * 
 * @copyright Copyright (c) 2024
 */
#include <stdio.h>
#include <stdlib.h>

#include "GameWorld.h"
#include "ResourceManager.h"

#include "raylib.h"
//#include "raymath.h"
//#define RAYGUI_IMPLEMENTATION    // to use raygui, comment these three lines.
//#include "raygui.h"              // other compilation units must only include
//#undef RAYGUI_IMPLEMENTATION     // raygui.h

#include "RBT.h"

/**
 * @brief Creates a dinamically allocated GameWorld struct instance.
 */
GameWorld* createGameWorld( void ) {

    GameWorld *gw = (GameWorld*) malloc( sizeof( GameWorld ) );

    gw->arvore = newRBT();

    rbtPut(gw->arvore,20);
    rbtPut(gw->arvore,10);
    rbtPut(gw->arvore,5);
    rbtPut(gw->arvore,15);
    rbtPut(gw->arvore,30);
    rbtPut(gw->arvore,78);
    rbtPut(gw->arvore,7);
    // exemplo 1
    

    // exemplo 2
    /*for ( int i = 0; i < 7; i++ ) {
        bstPut( gw->arvore, i );
    }*/
    int redNodeCount = 0;   
    int currentRank = 0;
    int maxLevel = 0;
    rbtProcess(gw->arvore->root, &currentRank, 0 ,&redNodeCount,&maxLevel);
    rbtInOrder(gw->arvore->root);
    printf("\n");


    return gw;

}

/**
 * @brief Destroys a GameWindow object and its dependecies.
 */
void destroyGameWorld( GameWorld *gw ) {
    free( gw );
}

/**
 * @brief Reads user input and updates the state of the game.
 */
void inputAndUpdateGameWorld( GameWorld *gw ) {

}

/**
 * @brief Draws the state of the game.
 */
void drawGameWorld( GameWorld *gw ) {

    // DESENHAR AQUI

    BeginDrawing();
    ClearBackground( WHITE );

    rbtDraw ( gw->arvore );


    
    EndDrawing();

}