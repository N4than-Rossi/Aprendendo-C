#include <stdio.h>

int main() {
    int a=1,b=6;

    while (a!=5){

        printf("\033[H\033[J");
        printf("===============================\n");
        printf("Calculadora Simples\n");
        printf("===============================\n");
        printf("Selecione uma operação:\n");
        printf("1. Adição\n");
        printf("2. Subtração\n");
        printf("3. Multiplicação\n");
        printf("4. Divisão\n");
        printf("5. Sair\n");
        printf("Opção:\n");
        scanf(" %d",&a);

        if (a>5 || a<1){
            printf("Essa opção é inválida, por favor digitar outro número\n");
            while (scanf(" %d",&b) && (b<1 || b>5) ){
                printf("Essa opção é inválida, por favor digitar outro número\n");
            }
        a=b;
        }
        if(a==5){
            break;
        }


    printf("Digite o primeiro número:");
    float n1;
    scanf(" %f",&n1);

    printf("Digite o segundo número:");
    float n2;
    scanf(" %f",&n2);

    switch (a){
        case 1 :{
            printf("Resultado: %g + %g = %g\n", n1,n2,n1+n2);
            break;
        }
        case 2 :{
            printf("Resultado: %g - %g = %g\n", n1,n2,n1-n2);
            break;
        }
        case 3 :{
            printf("Resultado: %g * %g = %g\n", n1,n2,n1*n2);
            break;
        }
        case 4 :{
            if (n2 == 0){
                printf("Erro: Divisão por zero não é permitida.\n");
                break;
            }
            printf("Resultado: %g / %g = %g\n", n1,n2,n1/n2);
            break;
        }
        case 5 :{
            break;
        }
        }
        printf("Deseja realizar outra operação? (s/n):");
        char aux;
        scanf(" %c",&aux);
        if (aux !='s' && aux != 'n'){
            printf("Resposta inválida. Por favor, digite 's' para sim ou 'n' para não.\n");
            while (scanf(" %c",&aux) && (aux!='s' && aux!='n')){
                printf("Resposta inválida. Por favor, digite 's' para sim ou 'n' para não.\n");
            }
        }
        if (aux == 'n'){
            break;
        }
    }
    printf("Obrigado por usar a calculadora! Até a próxima.");
    return 0;

}


