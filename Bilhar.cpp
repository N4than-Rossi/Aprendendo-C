//OBI 2016 - Nivel 1

#include <bits/stdc++.h>

using namespace std;

int main(){
	int a,aux=0;
	cin>>a;
	set<int> s;

	for (int i=0;i<a;i++){
        int n;
        cin>>n;

        if (s.find(n)==s.end()){
            s.insert(n);
            aux += 2;
        }
        else {
            s.erase(n);
        }

    }
    cout<<aux;

}
