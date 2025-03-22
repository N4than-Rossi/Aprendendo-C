//OBI 2014 - Nivel 2

#include <bits/stdc++.h>
#include <stdio.h>

using namespace std;

int main(){
    string a;
    getline(cin,a);
    for(int i=0;i<a.size();i++){
        if (a[i]=='p'){
            if(a[i+1]=='p'){
                a[i]=0;
                i++;
            }
            else{
                a[i]=0;
            }
        }
    }
    for (int i=0;i<a.size();i++){
        if (a[i]!=0){
            cout<<a[i];
        }
    }
}
