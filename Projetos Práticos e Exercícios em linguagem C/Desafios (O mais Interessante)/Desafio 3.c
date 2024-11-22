#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int numero;
    char nome[100];
    int serie;
    float nota1;
    float nota2;
    float nota3;
    float media;
} Aluno;

Aluno alunos[50];

void cadastrarAluno(int* quantidade);
int menu(void);
float calcularMedia(float x, float y, float z);
int buscarAluno(int x, Aluno* alunos, int quantidade);

int main(void) {
    int escolha;
    int quantidade = 0;
    int alunoBuscar, posicaoEncontrada;

    do {
        escolha = menu();

        switch (escolha) {
            case 1:
                cadastrarAluno(&quantidade);
                break;

            case 2:
                printf("Digite o número do aluno que deseja buscar: ");
                scanf("%d", &alunoBuscar);
                posicaoEncontrada = buscarAluno(alunoBuscar, alunos, quantidade);
                if (posicaoEncontrada == -1) {
                    printf("Aluno não encontrado.\n");
                } else {
                    printf("Aluno encontrado:\n");
                    printf("Nome: %sNúmero: %d\nSérie: %d\n",
                           alunos[posicaoEncontrada].nome,
                           alunos[posicaoEncontrada].numero,
                           alunos[posicaoEncontrada].serie);
                }
                break;

            case 3:
                printf("Digite o número do aluno que deseja calcular a média: ");
                scanf("%d", &alunoBuscar);
                posicaoEncontrada = buscarAluno(alunoBuscar, alunos, quantidade);
                if (posicaoEncontrada == -1) {
                    printf("Aluno não encontrado.\n");
                } else {
                    alunos[posicaoEncontrada].media = calcularMedia(
                        alunos[posicaoEncontrada].nota1,
                        alunos[posicaoEncontrada].nota2,
                        alunos[posicaoEncontrada].nota3);
                    printf("Média do aluno %s: %.2f\n",
                           alunos[posicaoEncontrada].nome,
                           alunos[posicaoEncontrada].media);
                }
                break;

            case 4:
                printf("Saindo do programa...\n");
                break;

            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (escolha != 4);

    return 0;
}

void cadastrarAluno(int* quantidade) {
    if (*quantidade >= 50) {
        printf("Limite máximo de alunos atingido!\n");
        return;
    }

    Aluno* novoAluno = &alunos[*quantidade];

    getchar();
    printf("Digite o nome do aluno: ");
    fgets(novoAluno->nome, sizeof(novoAluno->nome), stdin);
    novoAluno->nome[strcspn(novoAluno->nome, "\n")] = '\0';

    printf("Digite o número do aluno: ");
    scanf("%d", &novoAluno->numero);

    printf("Digite a série do aluno: ");
    scanf("%d", &novoAluno->serie);

    printf("Digite a nota 1: ");
    scanf("%f", &novoAluno->nota1);

    printf("Digite a nota 2: ");
    scanf("%f", &novoAluno->nota2);

    printf("Digite a nota 3: ");
    scanf("%f", &novoAluno->nota3);

    novoAluno->media = 0.0;

    (*quantidade)++;
    printf("Aluno cadastrado com sucesso!\n");
}

int menu(void) {
    int escolha;
    printf("\n=========== MENU ===========\n");
    printf("1 - Cadastrar aluno e notas\n");
    printf("2 - Buscar aluno\n");
    printf("3 - Calcular média de um aluno\n");
    printf("4 - Sair\n");
    printf("============================\n");
    printf("Escolha uma opção: ");
    scanf("%d", &escolha);
    return escolha;
}

int buscarAluno(int numero, Aluno* alunos, int quantidade) {
    if (quantidade == 0) {
        printf("Não existem alunos cadastrados!\n");
        return -1;
    }

    for (int i = 0; i < quantidade; i++) {
        if (alunos[i].numero == numero) {
            return i;
        }
    }

    return -1;
}

float calcularMedia(float x, float y, float z) {
    return (x + y + z) / 3.0;
}
