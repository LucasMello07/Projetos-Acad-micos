/**
 * @file main.c
 * @author Prof. Dr. David Buzatto
 * @brief Main function and logic for the game. Base template for game
 * development in C using Raylib (https://www.raylib.com/).
 * 
 * @copyright Copyright (c) 2024
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdarg.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <assert.h>

/*---------------------------------------------
 * Library headers.
 --------------------------------------------*/
#include <raylib.h>
//#include <raymath.h>

//#define RAYGUI_IMPLEMENTATION
//#include <raygui.h>
//#undef RAYGUI_IMPLEMENTATION

/*---------------------------------------------
 * Project headers.
 --------------------------------------------*/
#include <utils.h>

/*---------------------------------------------
 * Macros. 
 --------------------------------------------*/
#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 450
#define WINDOW_TITLE "Quadrado Latino"
#define WINDOW_TARGET_FPS 100
#define WINDOW_ANTIALIASING
//#define WINDOW_RESIZABLE
//#define WINDOW_FULL_SCREEN
//#define WINDOW_UNDECORATED
//#define WINDOW_ALWAYS_ON_TOP
//#define WINDOW_ALWAYS_RUN
//#define WINDOW_INIT_AUDIO

#define tam 4 // Definido tam único

/*--------------------------------------------
 * Constants. 
 -------------------------------------------*/


/*---------------------------------------------
 * Custom types (enums, structs, unions etc.).
 --------------------------------------------*/
typedef struct GameWorld {
    int dummy;
} GameWorld;


/*---------------------------------------------
 * Global variables.
 --------------------------------------------*/
GameWorld gw;

// o que vai dentro predefinido
char quadrado[tam][tam] = {
    { 'B', ' ', ' ', 'D' },
    { ' ', 'D', 'B', ' ' },
    { ' ', 'C', 'D', ' ' },
    { 'D', ' ', ' ', 'C' },
};


int tamanhoGlobal = 0;
int *sequencial;

char letrasDentro[] = {'A','B','C','D'};

int tamLetras = sizeof(letrasDentro) / sizeof(letrasDentro[0]);

//LINHAS E COLUNAS
char saida[tam][tam] = { 0 };

bool temSolucao;


/*---------------------------------------------
 * Function prototypes. 
 --------------------------------------------*/
/**
 * @brief Reads user input and updates the state of the game.
 * @param gw GameWorld struct pointer.
 */
void inputAndUpdate( GameWorld *gw );

/**
 * @brief Draws the state of the game.
 * @param gw GameWorld struct pointer.
 */
void draw( const GameWorld *gw );

/**
 * @brief Create the global Game World object and all of its dependencies.
 */
void createGameWorld( void );

/**
 * @brief Destroy the global Game World object and all of its dependencies.
 */
void destroyGameWorld( void );

/**
 * @brief Load game resources like images, textures, sounds,
 * fonts, shaders etc.
 */
void loadResources( void );

/**
 * @brief Unload the once loaded game resources.
 */
void unloadResources( void );

//funções
bool resolver(int posição); 

bool ehLinhaValida(char letra, int linha);  //Verifica se tem a letra na linha

bool EhColunaValida(char letra, int coluna); //Verifica se tem a letra na coluna

//"Anda" as posições
int GerarPosição(); 


int main( void ) {

    #ifdef WINDOW_ANTIALIASING
        SetConfigFlags( FLAG_MSAA_4X_HINT );
    #endif

    #ifdef WINDOW_RESIZABLE
        SetConfigFlags( FLAG_WINDOW_RESIZABLE );
    #endif

    #ifdef WINDOW_FULL_SCREEN
        SetConfigFlags( FLAG_FULLSCREEN_MODE );
    #endif

    #ifdef WINDOW_UNDECORATED
        SetConfigFlags( FLAG_WINDOW_UNDECORATED );
    #endif

    #ifdef WINDOW_ALWAYS_ON_TOP
        SetConfigFlags( FLAG_WINDOW_TOPMOST );
    #endif

    #ifdef WINDOW_ALWAYS_RUN
        SetConfigFlags( FLAG_WINDOW_ALWAYS_RUN );
    #endif

    InitWindow( WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE );
    #ifdef WINDOW_INIT_AUDIO
        InitAudioDevice();
    #endif
    SetTargetFPS( WINDOW_TARGET_FPS );    

    loadResources();
    createGameWorld();
    while ( !WindowShouldClose() ) {
        inputAndUpdate( &gw );
        draw( &gw );
    }
    unloadResources();
    destroyGameWorld();

    #ifdef WINDOW_INIT_AUDIO
        CloseAudioDevice();
    #endif
    CloseWindow();
    return 0;

}

void inputAndUpdate( GameWorld *gw ) {

}

void draw( const GameWorld *gw ) {

    BeginDrawing();
    ClearBackground( WHITE );

    const int largQuadrado = 50;

    for (int i = 0; i < tam; i++){
        for (int j = 0; j < tam; j++){

            Color c = WHITE;
            char texto = ' ';

            switch (saida[i][j]){
                case ' ': texto = ' '; break;
                case 'A': texto = 'A'; break;
                case 'B': texto = 'B'; break;
                case 'C': texto = 'C'; break;
                case 'D': texto = 'D'; break;           
            }

           
            DrawRectangle(j * largQuadrado, i * largQuadrado, largQuadrado, largQuadrado, c); // Montar o quadrado
            DrawText(TextFormat("%c",texto),(j * largQuadrado) + largQuadrado/3,(i * largQuadrado) + largQuadrado/4,30,BLUE); // Montar as letras
            
        }
    }
    
    // Linhas

    for( int i=0; i<=tam; i++ ) {
        DrawLine( 0, i*largQuadrado, tam * largQuadrado, i*largQuadrado, BLACK);
    }
    for( int i=0; i<=tam; i++ ) {
        DrawLine(i*largQuadrado, 0, i*largQuadrado, tam*largQuadrado, BLACK);
    }
    EndDrawing();

}


void createGameWorld( void ) {

    printf( "creating game world...\n" );

    gw = (GameWorld) {
        .dummy = 0
    };

    // retoma a função (char quadrado) para validar as letras que podem ser colocadas
    for (int i = 0; i < tam; i++){
        for (int j = 0; j < tam; j++){
            if (quadrado[i][j] == 'A'){
                saida[i][j] = 'A';
            }
            else if (quadrado[i][j] == 'B'){
                saida[i][j] = 'B';
            }
            else if (quadrado[i][j] == 'C'){
                saida[i][j] = 'C';
            }
            else if (quadrado[i][j] == 'D'){
                saida[i][j] = 'D';
            }
            else {
                saida[i][j] = ' ';
            }
        }
    }

    tamanhoGlobal = GerarPosição();
    temSolucao = resolver(0);
}


void destroyGameWorld( void ) {
    printf( "destroying game world...\n" );
}


void loadResources( void ) {
    printf( "loading resources...\n" );
}


void unloadResources( void ) {
    printf( "unloading resources...\n" );
}

bool resolver(int posição){
    if (posição < tamanhoGlobal){
        int linha = sequencial[posição] / tam;
        int coluna = sequencial[posição] % tam;
        int erros = 0;

        for (int i=0; i<tamLetras;i++){
            if (ehLinhaValida(letrasDentro[i],linha) && EhColunaValida(letrasDentro[i],coluna)){
                saida[linha][coluna] = letrasDentro[i];

                if (!resolver(posição+1)){
                    saida[linha][coluna] = ' ';
                }
            }
            else{
                erros++;
            }
        }

        if (erros == tamLetras){
            return false;
        }

        return true;
    }
    return true;
}


int GerarPosição(){
    int tamanho = 0;

    for (int i = 0; i < tam; i++){
        for (int j = 0; j < tam; j++){
            if (quadrado[i][j] == ' '){
                tamanho++;
            }
        }
    }

    sequencial = (int*)malloc(tamanho * sizeof(int));

    int PosicaoAtual = 0;
    int cont = 0;
    
    for (int i = 0; i < tam; i++){
        for (int j = 0; j < tam; j++){
            if (quadrado[i][j] == ' '){
                sequencial[cont] = PosicaoAtual;
                cont++; 
            }
            PosicaoAtual++;
        }
    }

    printf("%d ",tamanho);


    for (int i = 0; i < tamanho; i++){
        printf("%d ",sequencial[i]);
    }
    
    return tamanho;
}

bool ehLinhaValida(char letra, int linha){
    for (int i = 0; i < tam; i++){
        if (saida[linha][i] == letra){
            return false;
        }
    }
    return true;
}

bool EhColunaValida(char letra, int coluna){
    for (int i = 0; i < tam; i++){
        if (saida[i][coluna] == letra){
            return false;
        }
    }
    return true;
}

