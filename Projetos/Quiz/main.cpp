#include <bits/stdc++.h>

using namespace std;

struct Perguntas {

    string e;
    string op1[4];
    char c;

};

bool compara(pair<string, int>& a, pair<string, int>& b) {
    return a.second > b.second;
}


int main (){
    //Perguntas v[10];
    char r[11];
    char r2[11];
    int r_aux=0;


    FILE *p;
    p = fopen("perguntas.txt","a");
    if (p==NULL){
        printf("Erro: Arquivo 'perguntas.txt' nao encontrado ou invalido.");
        fclose(p);
        return 0;
    }
    fclose(p);




    char a[100];
    int i,ii;
    p = fopen("perguntas.txt","r");
    if (p==NULL){
        printf("Erro: Arquivo 'perguntas.txt' nao encontrado ou invalido.");
        fclose(p);
        return 0;
    }

    char c;
    while (feof(p) == 0){
        i=0,ii=0;
        while (1){
            c = fgetc(p);
            if (c=='\n' || c == EOF)break;

            a[i]=c;
            i++;
        }
        a[i]=0;

        if (i==1){
            char abc;
            scanf(" %c",&abc);
            while (abc!='A'&&abc!='a'&&abc!='B'&&abc!='b'&&abc!='C'&&abc!='c'&&abc!='D'&&abc!='d'){
                cout<<"Opcao invalida. Digite novamente (A-D): "<<endl;
                scanf(" %c",&abc);
            }
            r[r_aux]=a[0];
            r2[r_aux]=abc;
            r_aux++;
        }
        else {
            printf("%s\n",a);
        }
    }

    fclose(p);

    int acertos=0;
    for (int pw=0;pw<10;pw++){
        if (r2[pw]==r[pw]||r[pw]==toupper(r2[pw])){//Feito assim para detectar minusculas e maiusculas
            acertos++;
        }
    }
    cout<<"Quiz finalizado!\nVoce acertou "<<acertos<<" de 10 perguntas.\n\nDigite seu primeiro nome:";
    string nome;
    cin>>nome;
//-------------------------------------------------------------------------------------------------------
//daqui para baixo ele analisa o ranking:

    p = fopen("perguntas.txt","a");
    fclose(p);

    ifstream f("ranking.txt");
    if (!f.is_open()) {
        ofstream create("ranking.txt");
        create.close();
    }
    string str;
    int kk=0,nk=0;
    pair<string,int> par[25];

    while(f>>par[kk].first>>par[kk].second){
        if (nome==par[kk].first){
            nk=1;
            if (acertos>par[kk].second){
                par[kk].second=acertos;
            }
        }
        kk++;
    }
    if (!nk){
        par[kk].first=nome;
        par[kk].second=acertos;
    }
    sort(par,par+kk+1,compara);
    f.close();
    ofstream f2("ranking.txt");

    system("cls");
    cout<<"\n-------------------------\nRanking:\n";

    for (int y=0;y<=kk-nk;y++){
        f2<<par[y].first<<" "<<par[y].second<<" "<<endl;
        cout<<par[y].first<<" "<<par[y].second<<" "<<endl;
    }



    f2.close();
}
