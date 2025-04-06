#include <stdio.h>
#include <stdlib.h>

int main (){

    int a=1;
    FILE *p = fopen("estoque.txt", "w");
    fclose(p);//inicializando arquivo em branco

    while (a!=4){
        printf("\033[H\033[J");
        printf("================================\n");
        printf("   Controle de Estoque\n");
        printf("================================\n");
        printf("Selecione uma opção:\n");
        printf("1. Adicionar Item\n");
        printf("2. Remover Item\n");
        printf("3. Listar Estoque\n");
        printf("4. Sair\n");
        printf("Opção:\n");
        scanf(" %d",&a);


        if (a<1||a>4){
            printf("Opção inválida! Tente novamente.");
            while(scanf(" %d",&a)&&(a<1||a>4)){
                printf("Opção inválida! Tente novamente.");
            }
        }
        if (a==4){
            break;}

        switch (a){
            case 1:{
                char c[200];
                int qnt;
                printf("Digite o nome do item: ");
                int z=0;
                while (z!=-1){
                    scanf("%c",&c[z]);
                    if ((c[z] == '\n')&&z>0){
                        z=-2;
                    }
                    if(c[z]!='\n'){ //funciona para não ter o '\n' no inicio da string
                    z++;}
                }
                printf("Digite a quantidade: ");
                scanf(" %d",&qnt);
                //--------------------------------------------
                //manipulação do arquivo:
                FILE *p;
                p = fopen("estoque.txt", "a");
                fprintf(p,"%s%d\n",c,qnt);
                fclose(p);
                //--------------------------------------------
                printf("Item adicionado com sucesso!\n");
                break;
            }
            case 2:{
                char c[200];
                int qnt;
                printf("Digite o nome do item: ");
                int z=0;
                while (z!=-1){
                    scanf("%c",&c[z]);
                    if ((c[z] == '\n')&&z>0){
                        z=-2;
                    }
                    if(c[z]!='\n'){ //funciona para não ter o '\n' no inicio da string
                    z++;}
                }
                printf("Digite a quantidade a ser removida: ");
                scanf(" %d",&qnt);
                //
                //adicionar sistema de retirada do estoque
                //
                break;
           }
           case 3:{
               //
               //ler o conteúdo do estoque do arquivo
               //
               printf("\033[H\033[J");
               printf("=============================\n");
               printf("        Estoque Atual\n");
               printf("=============================\n");
                break;
                //
                //adicionar leitura de estoque
                //

           }
            case 4:{
                break;
           }
        }
        printf("Deseja realizar outra operação? (s/n):");
        char opc;
        scanf(" %c",&opc);
        if (opc=='n'||opc=='N'){
            break;
        }

    }
    printf("Obrigado por usar o Controle de Estoques! Até a próxima.");
}

