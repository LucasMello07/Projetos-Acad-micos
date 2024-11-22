/*

    Desenvolver um código em liguagem C para um hospital
    com o objetivo de gerenciar o cadastro de pacientes.

    1. O sistema deve ter um menu com as seguintes opções:
        a. Cadastrar paciente
        b. Exibir lista de pacientes
        c. Apagar paciente pelo seu numero
        d. Alterar paciente
        e. Calcular a idade média dos pacientes
        f. Exibir paciente de maior idade
        g. Sair

    2. Cada paciente deve ter armazenado os seguintes dados:
        - Número único
        - Nome
        - Endereço
        - Idade

    3. O sistema deve aceitar até 10 pacientes devida à
    restrição de leitos. Use #define

    4. O sistema deve garantir, no momento de cadastrar o paciente,
    que o número dele não está previamente cadastrado no sistema

    5. Use obrigatóriamente:
        - Structs
        - Vetores
        - Funções
    Sendo uma função (pelo menos) para cada opção exigida no sistema
    (ou seja: uma função para cadastrar, exibir, alterar, etc..)

    6. O sistema deve rodar continuamente, até que a opção de
     sair seja selecionada.

    7. Na função MAIN, usar ao máximo chamadas para funções.

*/

#include <stdio.h>
#include <stdlib.h>

#define TAM 10
int iii = 1;
struct paciente {
        int numero;
        char nome[50];
        char endereco[50];
        int idade;
};


struct paciente MaiorIdadePaciente(struct paciente Pacientes[]){
int maior = 0;
int nun = 0;
for(int j = 1; j < iii; j++){


    if(maior < Pacientes[j].idade){
        maior = Pacientes[j].idade;
        nun = j;
    }
}

printf("O paciente de maior idade e %s\n", Pacientes[nun].nome);

return;
};

struct paciente IdadeMediaPaciente(struct paciente Pacientes[]){

float mediaidade = 0;
float mediaidadef = 0;
int ii3 = iii - 1;


for(int j = 1; j < iii; j ++){

    mediaidade = mediaidade + Pacientes[j].idade;
}

mediaidadef = mediaidade / ii3;
printf("Media das idades: %.2f\n", mediaidadef);


return;
};

struct paciente AlterarPaciente(struct paciente Pacientes[]){
int ppl = 0;

    printf("Digite o numero do paciente que deseja alterar: ");
    scanf("%d", &ppl);
    printf("Digite o nome do paciente: ");
    scanf("%s", Pacientes[ppl].nome);
    //fflush(stdin);
    printf("Digite a idade do paciente: ");
    scanf(" %d", &Pacientes[ppl].idade);
    //fflush(stdin);
    printf("Digite o endereco do paciente(em vez de espaco coloque -): ");
    scanf(" %s", &Pacientes[ppl].endereco);
    //gets(Pacientes[iii].endereco);
    //fgets(Pacientes[iii].endereco, 50, stdin);
    //getchar();
    //fflush(stdin);


return;
};

struct paciente CadastrarPaciente(struct paciente Pacientes[]){

    //struct paciente p;
    Pacientes[iii].numero = iii;
    printf("Digite o nome do paciente: ");
    gets(Pacientes[iii].nome);
    //fflush(stdin);
    printf("Digite a idade do paciente: ");
    scanf(" %d", &Pacientes[iii].idade);
    //fflush(stdin);
    printf("Digite o endereco do paciente(em vez de espaco coloque -): ");
    scanf(" %s", &Pacientes[iii].endereco);
    //gets(Pacientes[iii].endereco);
    //fgets(Pacientes[iii].endereco, 50, stdin);
    //getchar();
    //fflush(stdin);

    iii++;
return;
};

struct paciente ListaPacientes(struct paciente Pacientes[]){

for(int j = 1; j < iii; j++){
        if(Pacientes[j].nome != NULL){
    printf("Numero Unico: %d\n", Pacientes[j].numero);
    printf("Nome: %s\n", Pacientes[j].nome);
    printf("Idade: %d\n", Pacientes[j].idade);
    printf("Endereco: %s\n", Pacientes[j].endereco);
        }
}

return;
};

struct paciente ApagarPaciente(struct paciente Pacientes[]){
int k = 0;

    printf("Digite o numero do paciente: ");
    scanf("%d", &k);
    Pacientes[k].numero = NULL;
    Pacientes[k].nome[50] = NULL;
    Pacientes[k].idade = NULL;
    Pacientes[k].endereco[50] = NULL;


};

void Menu(struct paciente Pacientes[]){

int escolha = 0;

    do{
        escolha = 0;

        printf("-------------------------------------------------\n");
        printf("Escolha uma das opcoes para proseguir: \n");
        printf("    1. Cadastrar Paciente.\n");
        printf("    2. Exibir lista de pacientes.\n");
        printf("    3. Apagar paciente pelo seu numero.\n");
        printf("    4. Alterar paciente.\n");
        printf("    5. Calcular a idade media dos pacientes.\n");
        printf("    6. Exibir paciente de maior idade.\n");
        printf("    7. Sair.\n");
        printf("-------------------------------------------------\n");

        printf("Opcao que deseja escolher: ");
        scanf("%d", &escolha);
        fflush(stdin);
        if(escolha == 1){
            CadastrarPaciente(Pacientes);
        }else if(escolha == 2){
            ListaPacientes(Pacientes);
        }else if(escolha == 3){
            ApagarPaciente(Pacientes);
        }else if(escolha == 4){
            AlterarPaciente(Pacientes);
        }else if(escolha == 5){
            IdadeMediaPaciente(Pacientes);
        }else if(escolha == 6){
            MaiorIdadePaciente(Pacientes);
        }

    }while(escolha != 7);
}

int main(){

struct paciente Pacientes[TAM];
Menu(Pacientes);

return 0;
}
