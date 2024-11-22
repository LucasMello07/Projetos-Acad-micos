#pragma once

#include <stdio.h>
#include <stdlib.h>

struct GameWorld;

typedef struct ArrayCopy {
    int* data;
    size_t size;
    struct ArrayCopy* previous;
    size_t inicio ;
    size_t meio ;
    size_t fim ;
} ArrayCopy;

ArrayCopy* createArrayCopy( struct GameWorld* gw );
void destroyArrayCopy( ArrayCopy* copy );