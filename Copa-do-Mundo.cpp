//OBI 2010 - Nivel 1

#include <bits/stdc++.h>
#include <stdio.h>

using namespace std;

int main(){
    queue <char> q;
    for (char i='A';i<='P';i++){
        q.push(i);
    }
    for (int i=0;i<15;i++){
        int a,b;
        cin>>a>>b;
        char t1=q.front();
        q.pop();
        char t2=q.front();
        q.pop();
        if (a>b){
            q.push(t1);
        }
        else {
            q.push(t2);
        }
    }
    cout << q.front();
}
