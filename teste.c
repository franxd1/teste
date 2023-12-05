#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif
#define quantidadeDEQuartos 30

typedef struct {
    char hospede[30];
} hotel;

void inicializarHotel(hotel nomedoHotel[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        nomedoHotel[i].hospede[0] = '\0';
    }
}

void inserirHospede(hotel nomedoHotel[], int numeroQuarto) {
    
    if (nomedoHotel[numeroQuarto - 1].hospede[0] == '\0') {
        printf("Digite o nome do hóspede: ");
        getchar();
        fgets(nomedoHotel[numeroQuarto - 1].hospede, sizeof(nomedoHotel[numeroQuarto - 1].hospede), stdin);
        nomedoHotel[numeroQuarto - 1].hospede[strcspn(nomedoHotel[numeroQuarto - 1].hospede, "\n")] = '\0';
        printf("Hóspede cadastrado com sucesso!\n");
        

    } else {
        printf("Quarto já ocupado. Escolha outro quarto.\n");
    }
    
        gerartxt(nomedoHotel, numeroQuarto);
}
void listarHospedes(hotel nomedoHotel[]) {
    printf("Lista de hóspede:\n");
    for (int i = 0; i < 30; i++) {
        if (nomedoHotel[i].hospede[0] != '\0') {
            printf("Quarto %d: %s\n", i + 1, nomedoHotel[i].hospede);
            gerartxt(nomedoHotel,i );
        }
    }
    system("pause");
    system("cls");
}
void buscarHospede(hotel nomedoHotel[]) {
    char nome[50];
    printf("Digite o nome do hóspede a ser buscado: ");
    getchar();
    fgets(nome, sizeof(nome), stdin);
    nome[strcspn(nome, "\n")] = '\0';

    for (int i = 0; i < quantidadeDEQuartos; i++) {
        if (strcmp(nomedoHotel[i].hospede, nome) == 0) {
            printf("%s está no quarto %d.\n", nome, i + 1);
            return;
        }
    }

    printf("%s não encontrado.\n", nome);
    system("pause");
    system("cls");
}
void editarHospede(hotel nomedoHotel[]) {
    int numeroDoQuarto;
    printf("Digite o número do quarto a ser editado: ");
    scanf("%d", &numeroDoQuarto);

    if (numeroDoQuarto >= 1 && numeroDoQuarto <= quantidadeDEQuartos) {
        if (nomedoHotel[numeroDoQuarto - 1].hospede[0] != '\0') {
            printf("Digite o novo nome do hóspede: ");
            scanf("%s", nomedoHotel[numeroDoQuarto - 1].hospede);
            printf("Hóspede editado com sucesso!\n");
        } else {
            printf("Quarto vazio. Nenhum hóspede para editar.\n");
        }
    } else {
        printf("Número de quarto invúlido.\n");
    }
    system("pause");
    system("cls");
}
void removerHospede(hotel nomedoHotel[]) {
    int quarto;
    printf("Digite o número do quarto a ser liberado: ");
    scanf("%d", &quarto);

    if (quarto >= 1 && quarto <= quantidadeDEQuartos) {
        if (nomedoHotel[quarto - 1].hospede[0] != '\0') {
            nomedoHotel[quarto - 1].hospede[0] = '\0';
            printf("Hóspede removido com sucesso!\n");
        } else {
            printf("Quarto vazio. Nenhum hopede para remover.\n");
        }
    } else {
        printf("Número de quarto inválido.\n");
    }
    system("pause");
    system("cls");
}
void quartosDisponiveis(hotel nomedoHotel[]) {
    printf("Quartos Disponíveis: \n");
    for (int i = 0; i < quantidadeDEQuartos; i++) {
        if(i<9){
            if (nomedoHotel[i].hospede[0] == '\0') {
            printf("QUARTO 0%d: ( )\n", i + 1);
        }else{
            printf("QUARTO 0%d: (x)\n", i + 1);
        }
        }else{
            if (nomedoHotel[i].hospede[0] == '\0') {
            printf("QUARTO %d: ( )\n", i + 1);
        }else{
            printf("QUARTO %d: (x)\n", i + 1);
        }
        }
        
    }
    printf("\n");
    system("pause");
    system("cls");
}
void gerartxt(hotel nomedoHotel[], int numeroQuartos) {
    FILE *pfile;
   
    pfile = fopen("C:\\Users\\55619\\Desktop\\pasta2\\texto", "a+");
    
    if (pfile != NULL) {
        fprintf(pfile, "Quarto:%d.", numeroQuartos);

        for (int i = 0; i < numeroQuartos; i++) {
            fprintf(pfile, "%s", nomedoHotel[i].hospede);
        }
        fprintf(pfile,"\n");
        fclose(pfile);
    
       return 1;
    } else {
        printf("Erro ao abrir o arquivo.\n");
    }
}

   




int main() {
    setlocale(LC_ALL, "Portuguese");
    hotel transilvania[30];
    inicializarHotel(transilvania, 30);
    

    int opcao;
    char inserirMaisHospedes;
    do {
        printf("\n============= Hotel Transilvânia ===============\n");
        printf("||  1. Inserir novo hóspede                   ||\n");
        printf("||  2. Listar hóspedes                        ||\n"); 
        printf("||  3. Buscar hóspede                         ||\n");
        printf("||  4. Editar hóspede                         ||\n");
        printf("||  5. Remover hóspede                        ||\n");
        printf("||  6. Mostrar quartos disponíveis            ||\n");
        printf("||  7. Salvar em arquivo Lista de Hóspedes    ||\n");
        printf("||  0. Sair                                    ||\n");
        printf("=================================================\n");
        printf("        Digite a opção desejada: ");
        scanf("%d", &opcao);
        system("cls");

        switch (opcao) {
            case 1:
                do{
                system("cls");
                printf("Digite o número do quarto: ");
                int numeroDoQuarto;
                scanf(" %d", &numeroDoQuarto);
                inserirHospede(transilvania, numeroDoQuarto);
                printf("Deseja inserir mais Hóspedes? (S) para Sim e (N) para Não: ");
                scanf(" %c", &inserirMaisHospedes);

                }while(inserirMaisHospedes != 'N');
                system("cls");
                break;
            case 2:
                system("cls");
                listarHospedes(transilvania);
                break;
            case 3:
                system("cls");
                buscarHospede(transilvania);
                break;
            case 4:
                system("cls");
                editarHospede(transilvania);
                break;
            case 5:
                system("cls");
                removerHospede(transilvania);
                break;
            case 6:
                system("cls");
                quartosDisponiveis(transilvania);
                break;
            case 7:
                printf("ARQUIVO GERADO COM SUCESSO!!"); 
                 #ifdef _WIN32
    Sleep(1000); 
    sleep(3);     // Espera por 3 segundos
    #endif
                system("cls");
          
                break;
            case 0:
                printf("Saindo do programa. Até logo!\n");
                system("pause");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }

    } while (opcao != 0);

    return 0;
}