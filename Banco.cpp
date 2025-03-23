//OBI 2012 - Nivel 2

#include <bits/stdc++.h>

using namespace std;

int main() {
    int c,n,aux=0;
    priority_queue<int,vector<int>, greater<int>> fila;
    cin>>c>>n;

    if (c>=n){
        cout<<0;
        return 0;
    }


    int d,t,tempo;
    for (int i=0;i<c;i++){
        cin>>d>>t;
        fila.push(d+t);
    }

    for (int i=c;i<n;i++){
        cin>>d>>t;
        if (fila.top()-d > 20){
            aux++;
        }

        tempo = max(fila.top(),d)+t; //tempo em que termina de ser atendido
        fila.pop();
        fila.push(tempo);
    }
    cout<<aux;
}
