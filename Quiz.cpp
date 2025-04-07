#include <bits/stdc++.h>

using namespace std;

struct Perguntas {

    string e;
    string op1[4];
    char c;

};

char* puxa_linha (){
    
    
}


int main (){
    Perguntas v[10];
    
    FILE *p;
    p = fopen("perguntas.txt","a");
    if (p==NULL){
        printf("Erro: Arquivo 'perguntas.txt' nao encontrado ou invalido.");
    }
    fclose(p);




    char a[100];
    int i;
    p = fopen("perguntas.txt","r");

    char c;
    while (feof(p) == 0){
        i=0;
        while (1){
            c = fgetc(p);
            if (c=='\n' || c == EOF)break;

            a[i]=c;
            i++;
        }
        a[i]=0;
        printf("%s\n",a);
        
        if (i==0){
            
        }
    }

    fclose(p);

}


