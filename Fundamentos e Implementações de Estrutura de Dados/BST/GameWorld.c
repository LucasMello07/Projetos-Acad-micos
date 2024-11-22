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

#include "BST.h"

/**
 * @brief Creates a dinamically allocated GameWorld struct instance.
 */
GameWorld* createGameWorld( void ) {

    GameWorld *gw = (GameWorld*) malloc( sizeof( GameWorld ) );

    gw->arvore = newBST();

    // exemplo 1
    bstPut( gw->arvore, 20 );
    bstPut( gw->arvore, 10 );
    bstPut( gw->arvore, 5 );
    bstPut( gw->arvore, 15 );
    bstPut( gw->arvore, 30 );
    bstPut( gw->arvore, 25 );
    bstPut( gw->arvore, 35 );

    // exemplo 2
    /*for ( int i = 0; i < 7; i++ ) {
        bstPut( gw->arvore, i );
    }*/

    int currentRank = 0;
    int maxLevel = 0;
    bstProcess( gw->arvore->root, &currentRank, 0, &maxLevel );

    bstInOrder( gw->arvore->root );
    printf( "\n" );

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

    bstDraw ( gw->arvore );


    
    EndDrawing();

}