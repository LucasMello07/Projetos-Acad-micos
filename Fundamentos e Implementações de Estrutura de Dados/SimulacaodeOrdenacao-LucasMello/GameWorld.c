/**
 * @file GameWorld.h
 * @author Prof. Dr. David Buzatto
 * @brief GameWorld implementation.
 * 
 * @copyright Copyright (c) 2024
 */
#include <stdio.h>
#include <stdlib.h>

#include "raylib.h"
//#include "raymath.h"
//#define RAYGUI_IMPLEMENTATION
//#include "raygui.h"
//#undef RAYGUI_IMPLEMENTATION

#include "GameWorld.h"
#include "ResourceManager.h"
#include "SortingAlgorithms.h"

#define ARRAY_SIZE 9
#define TIME_TO_WAIT 0.5

GameWorld* createGameWorld( void ) {

    GameWorld *gw = (GameWorld*) malloc( sizeof( GameWorld ) );
    *gw = (GameWorld){0};

    gw->size = ARRAY_SIZE;
    gw->array = (int*) malloc( sizeof(int) * gw->size );
    gw->timeToWait = TIME_TO_WAIT;

    populateArray( gw->array, gw->size );
    shuffeArray( gw->array, gw->size );
    createAndAddNewArrayCopy( gw , 0, 0, 0);
    gw->currentCopy = gw->copiesHead;
    
    //selectionSort( gw );
    //insertionSort( gw );
    //bubbleSort( gw );
    //shellSort( gw );
    mergeSort( gw );
    //quickSort( gw );
    //heapSort( gw );

    return gw;

}

void destroyGameWorld( GameWorld *gw ) {

    ArrayCopy* current = gw->copiesHead;
    while ( current != NULL ) {
        ArrayCopy* previous = current->previous;
        destroyArrayCopy( current );
        current = previous;
    }

    free( gw->array );
    free( gw );

}

void inputAndUpdateGameWorld( GameWorld *gw ) {

    gw->timeAcum += GetFrameTime();

    if ( gw->timeAcum >= gw->timeToWait ) {
        gw->timeAcum = 0;
        if ( gw->currentCopy != NULL && gw->currentCopy->previous != NULL ) {
            gw->currentCopy = gw->currentCopy->previous;
        }
    }

}

void drawGameWorld( GameWorld *gw ) {

    BeginDrawing();
    ClearBackground( BLACK );

    if ( gw->currentCopy != NULL ) {

        int margin = 20;
        int unitHeight = ( GetScreenHeight() - margin * 2 ) / gw->size;
        int valueWidth = ( GetScreenWidth() - margin * 2 ) / gw->size;
        int valueSpacing = 0;
        int startY = GetScreenHeight() - margin;

        int* array = gw->currentCopy->data;
        
        for ( size_t i = 0; i < gw->size; i++ ) {
            Color c = DARKGREEN ;
            int valueHeight = unitHeight * array[i];
             if (i == gw->currentCopy->fim) {
                c = RED ;
            } else if (i == gw->currentCopy->inicio){
                c = BLUE ;
            } else if (i == gw->currentCopy->meio) {
                c = DARKPURPLE ;
            }
            DrawRectangle( 
                margin + ( valueWidth + valueSpacing ) * i,
                startY - valueHeight,
                valueWidth, 
                valueHeight,
                c
            );
        }

    }

    EndDrawing();

}

void createAndAddNewArrayCopy( GameWorld* gw, int inicio, int meio, int fim) {

    ArrayCopy* copy = createArrayCopy( gw );
    copy->inicio = inicio ;
    copy->meio = meio ;
    copy->fim = fim ;

    if ( gw->copiesHead == NULL && gw->copiesTail == NULL ) {
        gw->copiesHead = copy;
        gw->copiesTail = copy;
    } else {
        gw->copiesTail->previous = copy;
        gw->copiesTail = copy;
    }

}