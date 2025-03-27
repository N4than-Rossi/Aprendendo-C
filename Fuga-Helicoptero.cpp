//OBI 2016 - Nivel Junior

#include <bits/stdc++.h>

using namespace std;


int main(){
    int h,p,f,d;
    cin>>h>>p>>f>>d;
    h++,p++,f++;

    if (d==1){
        for (int i=f;i<50;i++){
            if (i%17==p){
                cout<<"N";
                return 0;
            }
            if (i%17==h){
                cout<<"S";
                return 0;
            }
        }
    }
    if (d==-1){
        for (int i=f+17;i>=0;i--){
            if (i%17==p){
                cout<<"N";
                return 0;
            }
            if (i%17==h){
                cout<<"S";
                return 0;
            }
        }
    }
}
