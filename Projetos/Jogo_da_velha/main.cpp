#include <bits/stdc++.h>

int main(){

    char a='a';
    int resultado=0;
    while (a!='n'&&a!='N'){
        char m[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
        int num;
        for (int j=0;j<=9;j++){
            system("cls");

            printf("JOGO DA VELHA\n\n");
            printf(" %c | %c | %c\n",m[0][0],m[0][1],m[0][2]);
            printf("-----------\n");
            printf(" %c | %c | %c\n",m[1][0],m[1][1],m[1][2]);
            printf("-----------\n");
            printf(" %c | %c | %c\n\n",m[2][0],m[2][1],m[2][2]);

            if (resultado!=0){
                printf("Parabéns! Jogador %d venceu!\n",resultado);
                resultado=0;
                break;
            }

            if(j==9){
                printf("Empate! Nenhum jogador venceu.\n");
                break;
            }

            printf("Jogador %d (%c), escolha uma posição: ",j%2+1,(j%2==0)?'X':'O');
            //scanf(" %d",&num);
            while(1){
            scanf(" %d",&num);
            int aux=num/3;
            if (num>0&&num<10){
                if (m[aux][num%3-1]!='X' && m[aux][num%3-1]!='O'){
                    m[aux][num%3-1] = (j%2==0)?'X':'O';
                    break;
                }
            }
            printf("Posição inválida ou já ocupada! Escolha outra posição: ");
            }
            for (int k=0;k<3;k++){
                //printf("algo");
                if (m[k][0]==m[k][1]&&m[k][0]==m[k][2]){
                    resultado = (j%2==0)?1:2;
                    break;
                }
                if (m[0][k]==m[1][k]&&m[0][k]==m[2][k]){
                    resultado = (j%2==0)?1:2;
                    break;
                }
            }
            if(m[0][0]==m[1][1]&&m[0][0]==m[2][2])resultado = (j%2==0)?1:2;
            if(m[0][2]==m[1][1]&&m[0][2]==m[2][0])resultado = (j%2==0)?1:2;
        }


        printf("Deseja jogar novamente? (S/N): ");
        scanf(" %c", &a);
    }
    return 0;
}
