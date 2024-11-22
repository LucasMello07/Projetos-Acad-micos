#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int isbn;
    char titulo[100];
    char autor[100];
    int paginas;
} Livro;

Livro biblioteca[50];

void cadastrarLivro(int* quantidade);
int buscarLivroPorISBN(int isbn, Livro* biblioteca, int quantidade);
int buscarLivroPorTitulo(char* titulo, Livro* biblioteca, int quantidade);
void calcularPaginasTotais(Livro* biblioteca, int quantidade);
void exibirLivros(Livro* biblioteca, int quantidade);
int menu(void);

int main(void) {
    int escolha, quantidade = 0;
    int isbnBuscar, posicaoEncontrada;
    char tituloBuscar[100];

    do {
        escolha = menu();

        switch (escolha) {
            case 1:
                cadastrarLivro(&quantidade);
                break;

            case 2:
                printf("Digite o ISBN do livro que deseja buscar: ");
                scanf("%d", &isbnBuscar);
                posicaoEncontrada = buscarLivroPorISBN(isbnBuscar, biblioteca, quantidade);
                if (posicaoEncontrada == -1) {
                    printf("Livro n�o encontrado.\n");
                } else {
                    printf("Livro encontrado:\n");
                    printf("ISBN: %d\nT�tulo: %s\nAutor: %s\nP�ginas: %d\n",
                           biblioteca[posicaoEncontrada].isbn,
                           biblioteca[posicaoEncontrada].titulo,
                           biblioteca[posicaoEncontrada].autor,
                           biblioteca[posicaoEncontrada].paginas);
                }
                break;

            case 3:
                getchar(); // Limpar buffer
                printf("Digite o t�tulo do livro que deseja buscar: ");
                fgets(tituloBuscar, sizeof(tituloBuscar), stdin);
                tituloBuscar[strcspn(tituloBuscar, "\n")] = '\0';
                posicaoEncontrada = buscarLivroPorTitulo(tituloBuscar, biblioteca, quantidade);
                if (posicaoEncontrada == -1) {
                    printf("Livro n�o encontrado.\n");
                } else {
                    printf("Livro encontrado:\n");
                    printf("ISBN: %d\nT�tulo: %s\nAutor: %s\nP�ginas: %d\n",
                           biblioteca[posicaoEncontrada].isbn,
                           biblioteca[posicaoEncontrada].titulo,
                           biblioteca[posicaoEncontrada].autor,
                           biblioteca[posicaoEncontrada].paginas);
                }
                break;

            case 4:
                calcularPaginasTotais(biblioteca, quantidade);
                break;

            case 5:
                exibirLivros(biblioteca, quantidade);
                break;

            case 6:
                printf("Saindo do programa...\n");
                break;

            default:
                printf("Op��o inv�lida. Tente novamente.\n");
        }
    } while (escolha != 6);

    return 0;
}

void cadastrarLivro(int* quantidade) {
    if (*quantidade >= 50) {
        printf("Limite m�ximo de livros atingido!\n");
        return;
    }

    Livro* novoLivro = &biblioteca[*quantidade];

    getchar();
    printf("Digite o t�tulo do livro: ");
    fgets(novoLivro->titulo, sizeof(novoLivro->titulo), stdin);
    novoLivro->titulo[strcspn(novoLivro->titulo, "\n")] = '\0';

    printf("Digite o autor do livro: ");
    fgets(novoLivro->autor, sizeof(novoLivro->autor), stdin);
    novoLivro->autor[strcspn(novoLivro->autor, "\n")] = '\0';

    printf("Digite o ISBN do livro: ");
    scanf("%d", &novoLivro->isbn);

    printf("Digite o n�mero de p�ginas do livro: ");
    scanf("%d", &novoLivro->paginas);

    (*quantidade)++;
    printf("Livro cadastrado com sucesso!\n");
}

int buscarLivroPorISBN(int isbn, Livro* biblioteca, int quantidade) {
    for (int i = 0; i < quantidade; i++) {
        if (biblioteca[i].isbn == isbn) {
            return i;
        }
    }
    return -1;
}

int buscarLivroPorTitulo(char* titulo, Livro* biblioteca, int quantidade) {
    for (int i = 0; i < quantidade; i++) {
        if (strcmp(biblioteca[i].titulo, titulo) == 0) {
            return i;
        }
    }
    return -1;
}

void calcularPaginasTotais(Livro* biblioteca, int quantidade) {
    int totalPaginas = 0;

    for (int i = 0; i < quantidade; i++) {
        totalPaginas += biblioteca[i].paginas;
    }

    printf("O total de p�ginas dos livros cadastrados �: %d\n", totalPaginas);
}

void exibirLivros(Livro* biblioteca, int quantidade) {
    if (quantidade == 0) {
        printf("Nenhum livro cadastrado.\n");
        return;
    }

    printf("Lista de livros cadastrados:\n");
    for (int i = 0; i < quantidade; i++) {
        printf("%d - T�tulo: %s | Autor: %s | ISBN: %d | P�ginas: %d\n",
               i + 1, biblioteca[i].titulo, biblioteca[i].autor, biblioteca[i].isbn, biblioteca[i].paginas);
    }
}

int menu(void) {
    int escolha;

    printf("\n=========== MENU ===========\n");
    printf("1 - Cadastrar livro\n");
    printf("2 - Buscar livro por ISBN\n");
    printf("3 - Buscar livro por t�tulo\n");
    printf("4 - Calcular total de p�ginas\n");
    printf("5 - Exibir todos os livros\n");
    printf("6 - Sair\n");
    printf("============================\n");
    printf("Escolha uma op��o: ");
    scanf("%d", &escolha);

    return escolha;
}
