//O Jogo da Vida de Conway é um processo de simulação (conhecido como autômato celular)
//criado pelo matemático britânico John Conway para reproduzir, por meio de uma matriz, processos de mudança em grupos de seres vivos

#include <bits/stdc++.h>
using namespace std;

int vizinhos (int p[][52][52],int i,int j,int num){
    int ans=0;
    if (p[num][i+1][j+1]==1)ans++;
    if (p[num][i+1][j]==1)ans++;
    if (p[num][i+1][j-1]==1)ans++;
    if (p[num][i-1][j+1]==1)ans++;
    if (p[num][i-1][j]==1)ans++;
    if (p[num][i-1][j-1]==1)ans++;
    if (p[num][i][j+1]==1)ans++;
    if (p[num][i][j-1]==1)ans++;
    return ans;
}


int main() {
    int n,q;
    bool num=1;
    cin>>n>>q;
    int m[2][52][52];
    string s[n+2];

    for (int i=0;i<n+2;i++){
        if(i>0 && i<n+1){
        //cin.tie(0);
        cin>>s[i];
        }
        for (int j=0;j<n+2;j++){
            if (i==0||i==n+1||j==0||j==n+1){
                m[0][i][j]=2;
                m[1][i][j]=2;
            }
            else{
                m[0][i][j]=s[i][j-1] - '0';
            }
        }
    }

    for (int k=0;k<q;k++){
        num = !num;
        for (int i=1;i<n+1;i++){
            for (int j=1;j<n+1;j++){
                int v=vizinhos(m,i,j,num);
                if(m[num][i][j]==0){
                    if (v==3)m[!num][i][j]=1;
                    if (v!=3)m[!num][i][j]=0;
                }
                if(m[num][i][j]==1){
                    if (v==3 || vizinhos(m,i,j,num)==2)m[!num][i][j]=1;
                    if (v!=3 && vizinhos(m,i,j,num)!=2)m[!num][i][j]=0;
                }
            }
        }
    }
    for (int i=1;i<n+1;i++){
        for (int j=1;j<n+1;j++){
            cout<<m[!num][i][j];
        }
        cout<<endl;
    }
    return 0;
}
