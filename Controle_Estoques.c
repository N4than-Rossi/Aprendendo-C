#include <stdio.h>
#include <stdlib.h>

int main (){


    int a=1, qnt;
    //FILE *p;
    char c[200];
    char temp[100][200];
    int temp1[100];
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

                printf("Digite o nome do item: ");
                scanf(" %s",&c);
                printf("Digite a quantidade: ");
                scanf(" %d",&qnt);

                //--------------------------------------------
                //manipulação do arquivo:

                p = fopen("estoque.txt", "a");
                fprintf(p,"%s\n%d\n",c,qnt);
                fclose(p);
                //--------------------------------------------
                printf("Item adicionado com sucesso!\n");
                break;
            }
            case 2:{

                p = fopen("estoque.txt", "r");
                printf("Digite o nome do item: ");
                scanf(" %s",&c);
                printf("Digite a quantidade a ser removida: ");
                scanf(" %d",&qnt);
                //
                char c2[200];
                int qnt2,kjk=1;
                int i=0;
                while ((fscanf(p," %s %d", &c2, &qnt2))==2){
                    if(strcmp(c, c2) == 0){
                        fclose(p);
                        kjk=0;
                        p = fopen("estoque.txt", "a");

                        if(qnt==qnt2){
                            printf("Item removido do estoque!\n");
                            //adicionar remoção
                        }
                        else if(qnt<qnt2){
                            printf("Quantidade atualizada com sucesso!\n");
                            strcpy(temp[i], c2);
                            temp1[i] = qnt2-qnt;
                            i++;
                            //atualizar quantia
                        }
                        else {
                            printf("Estoque insuficiente. Quantidade disponível: %d\n",qnt2);
                            strcpy(temp[i], c2);
                            temp1[i] = qnt2;
                            i++;
                        }
                    }
                    else {
                        strcpy(temp[i], c2);
                        temp1[i] = qnt2;
                        i++;
                    }
                }
                if (kjk){printf("Item não encontrado.\n");}
                fclose(p);

                p = fopen("estoque.txt", "w");
                for(int j=0;j<i;j++){
                    fprintf(p,"%s\n%d\n",temp[j],temp1[j]);
                }
                fclose(p);
                break;
           }
           case 3:{

                p = fopen("estoque.txt", "r");

                int cu = fgetc(p);
               if (cu == EOF){
                    printf("O estoque está vazio.\n");
                    fclose(p);
                    break;
               }
                rewind(p);
               printf("\033[H\033[J");
               printf("=============================\n");
               printf("        Estoque Atual\n");
               printf("=============================\n");
               while( fscanf(p, "%s %d", &c, &qnt) == 2 ){
                printf("Nome: %s\nQuantidade: %d\n\n",c,qnt);
               }
               fclose(p);
                break;

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

