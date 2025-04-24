//Sudoku solver
//training backtraking:

#include <bits/stdc++.h>
using namespace std;


bool Is_safe(vector<vector<int>>& v,int linha,int coluna,int num){
    for (int i=0;i<9;i++){
        if (v[linha][i]==num){
            return false;
        }
        if (v[i][coluna]==num){
            return false;
        }
    }
    int ini_linha=linha - linha%3;
    int ini_coluna=coluna - coluna%3;
    for (int i=ini_linha;i<ini_linha+3;i++){
        for (int j=ini_coluna;j<ini_coluna+3;j++){
            if (v[i][j]==num){
                return false;
            }
        }
    }
    return true;
}

bool tabuleiro_valido(vector<vector<int>>& v) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            int num = v[i][j];
            if (num != 0) {
                v[i][j] = 0; // Temporariamente zera
                if (!Is_safe(v, i, j, num)) {
                    return false;
                }
                v[i][j] = num; // Restaura valor
            }
        }
    }
    return true;
}

bool sudoku (vector<vector<int>>& v){
    bool vazio=false;
    int linha=-1,coluna=-1;
    for (linha=0;linha<9;linha++){ //está procurando um espaço vazio
        for (coluna=0;coluna<9;coluna++){
            if (v[linha][coluna]==0){
                vazio=true;
                break;
            }
        }
        if(vazio){
            break;
        }
    }
    if (!vazio){
        return true;
    }

    for (int i=1;i<=9;i++){ //vê qual número se encaixo naquele lugar
        if(Is_safe(v,linha,coluna,i)){
            v[linha][coluna]=i;
            if (sudoku(v)){
                return true;
            }
            v[linha][coluna]=0;

        }
    }
    return false;

}

int main() {
    vector<vector<int>> v(9, vector<int>(9));
    for (int i=0;i<9;i++){
        for (int j=0;j<9;j++){
            cin>>v[i][j];
        }
    }

    if (!tabuleiro_valido(v)) {
    cout << "NO SOLUTION";
    return 0;
}

    if (sudoku(v)){
        for (int i=0;i<9;i++){
            for (int j=0;j<9;j++){
                cout<<v[i][j]<<" ";
            }
            cout<<endl;
        }

    }
    else{
        cout<<"NO SOLUTION";
    }
    return 0;
}
