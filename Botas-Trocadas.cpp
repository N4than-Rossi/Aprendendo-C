//OBI 2017 - Nivel 2

#include <bits/stdc++.h>

using namespace std;


int main(){
    int n,aux=0;
    map<int,int> map_D;
    map<int,int> map_E;

    cin>>n;
    for (int i=0;i<n;i++){
        int a;
        char b;
        cin>>a>>b;
        if (b=='D'){
            if (map_D.find(a)==map_D.end()){
                map_D[a]=1;
            }
            else {
                map_D[a]++;
            }

            if (map_E.find(a)!=map_E.end()){
                aux++;
                map_E[a]--;
                map_D[a]--;
                if (map_E[a]==0){map_E.erase(a);}
                if (map_D[a]==0){map_D.erase(a);}
            }
        }
        //---------------------------------------------
        if (b=='E'){
            if (map_E.find(a)==map_E.end()){
                map_E[a]=1;
            }
            else {
                map_E[a]++;
            }

            if (map_D.find(a)!=map_D.end()){
                aux++;
                map_E[a]--;
                map_D[a]--;
                if (map_E[a]==0){map_E.erase(a);}
                if (map_D[a]==0){map_D.erase(a);}
            }
        }
    }
    cout<<aux;
}
