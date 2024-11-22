#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int opcaoPrincipal, opcaoVenda, quantidade, senha;
    float preco, valorPago, troco;
    char nomeUsuario[50];

    do {
        printf("\n=== Banca Regi�o � Vendas ===\n");
        printf("1. Vender Produto\n");
        printf("2. Trocar Funcion�rio\n");
        printf("3. Sair\n");
        printf("Escolha uma op��o: ");
        scanf("%d", &opcaoPrincipal);

        switch (opcaoPrincipal) {
            case 1:
                printf("\n=== Venda de Produtos ===\n");
                printf("1. Revista � R$ 2,00\n");
                printf("2. Jornal � R$ 3,50\n");
                printf("3. Livro � R$ 20,00\n");
                printf("4. Voltar\n");
                printf("Escolha uma op��o: ");
                scanf("%d", &opcaoVenda);

                switch (opcaoVenda) {
                    case 1:
                        preco = 2.0;
                        break;
                    case 2:
                        preco = 3.5;
                        break;
                    case 3:
                        preco = 20.0;
                        break;
                    case 4:
                        printf("Voltando ao menu principal...\n");
                        continue;
                    default:
                        printf("Op��o inv�lida! Tente novamente.\n");
                        continue;
                }

                printf("Qual foi a quantidade: ");
                scanf("%d", &quantidade);

                float total = preco * quantidade;
                printf("O pre�o total � R$ %.2f\n", total);

                printf("Digite o valor pago: ");
                scanf("%f", &valorPago);

                if (valorPago >= total) {
                    troco = valorPago - total;
                    printf("Troco: R$ %.2f\n", troco);
                } else {
                    printf("Valor pago insuficiente! Faltam R$ %.2f\n", total - valorPago);
                }
                break;

            case 2:
                printf("\n=== Trocar Funcion�rio ===\n");
                printf("Digite o nome do usu�rio: ");
                scanf(" %s", nomeUsuario);

                if (strcasecmp(nomeUsuario, "usuario") == 0) {
                    printf("Digite a senha: ");
                    scanf("%d", &senha);

                    if (senha == 123) {
                        printf("Usu�rio trocado com sucesso!\n");
                    } else {
                        printf("Senha inv�lida!\n");
                    }
                } else {
                    printf("Usu�rio inv�lido!\n");
                }
                break;

            case 3:
                printf("Saindo do sistema... At� logo!\n");
                break;

            default:
                printf("Op��o inv�lida! Escolha novamente.\n");
                break;
        }
    } while (opcaoPrincipal != 3);

    return 0;
}
