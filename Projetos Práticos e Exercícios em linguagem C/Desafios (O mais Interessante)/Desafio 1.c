#include <stdio.h>
#include <string.h>

#define qntSelecoes 2

typedef struct {
    char nome[51];
    int numJogadores;
    int copasVencidas;
} Selecao;

Selecao cadastrarSelecao();
void exibirSelecoes(Selecao exibeSelecao[]);
void mediaCopas(Selecao copasV[]);
void maiorNumJogadores(Selecao maiorNumeroJogadores[]);
void totalGols();

int main() {
    int i;
    Selecao selecoes[qntSelecoes];

    printf("-----------------Cadastrar Selecao-----------------\n\n");

    for (i = 0; i < qntSelecoes; i++) {
        printf("Selecao [%d]:\n", i + 1);
        selecoes[i] = cadastrarSelecao();
    }

    printf("-----------------Exibir Selecoes-----------------\n\n");
    exibirSelecoes(selecoes);
    mediaCopas(selecoes);
    maiorNumJogadores(selecoes);
    totalGols();

    return 0;
}

Selecao cadastrarSelecao() {
    Selecao selecao;

    printf("Digite o nome da selecao: \n");
    scanf(" %[^\n]", selecao.nome);
    printf("Digite o numero de jogadores: \n");
    scanf("%d", &selecao.numJogadores);
    printf("Copas vencidas: \n");
    scanf("%d", &selecao.copasVencidas);

    return selecao;
}

void exibirSelecoes(Selecao exibeSelecao[]) {
    int i;

    for (i = 0; i < qntSelecoes; i++) {
        printf("Selecao [%d]:\n", i + 1);
        printf(" Nome: %s\n Numero de jogadores: %d\n Copas vencidas: %d\n\n",
               exibeSelecao[i].nome, exibeSelecao[i].numJogadores, exibeSelecao[i].copasVencidas);
    }
}

void mediaCopas(Selecao copasV[]) {
    float media = 0.0;
    int i;

    for (i = 0; i < qntSelecoes; i++) {
        media += copasV[i].copasVencidas;
    }

    printf("Media de copas vencidas pelas selecoes cadastradas: %.2f\n\n", media / qntSelecoes);
}

void maiorNumJogadores(Selecao maiorNumeroJogadores[]) {
    int maiorNumero = 0;
    int i;

    for (i = 0; i < qntSelecoes; i++) {
        if (maiorNumero <= maiorNumeroJogadores[i].numJogadores) {
            maiorNumero = maiorNumeroJogadores[i].numJogadores;
        }
    }
    printf("Maior numero de jogadores: %d\n\n", maiorNumero);
}

void totalGols() {
    int golsMarcados[qntSelecoes][4];
    int soma = 0;
    int i, j;

    for (i = 0; i < qntSelecoes; i++) {
        printf("Selecao [%d]:\n", i + 1);
        soma = 0;

        for (j = 0; j < 4; j++) {
            printf(" Jogo %d: Gols Marcados: ", j + 1);
            scanf("%d", &golsMarcados[i][j]);
            soma += golsMarcados[i][j];
        }

        printf("A selecao %d marcou %d gols nessa copa.\n\n", i + 1, soma);
    }
}
