//OBI 2022 - Nivel Senior

#include <bits/stdc++.h>
using namespace std;

int main(){
    int m[10][10],n;
    int linha,coluna,soma1=0,soma2=0;

    cin>>n;

    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            cin>>m[i][j];
            if (m[i][j]==0){
                linha = i+1;
                coluna = j+1;
            }
        }
    }
    for (int i=0;i<n;i++){
        if (linha>1){
            soma1 += m[0][i];
            soma2 += m[linha-1][i];
        }
        else {
            soma1 += m[1][i];
            soma2 += m[linha-1][i];
        }
    }
    cout << soma1-soma2 << endl << linha << endl << coluna;

}
