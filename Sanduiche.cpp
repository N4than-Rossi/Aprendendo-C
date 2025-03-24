//OBI 2016 - Nivel 2
//ainda não completo

#include <bits/stdc++.h>

using namespace std;

int main(){
	int n,d,aux=0;
	cin>>n>>d;
	vector<int> vec;

	for (int i=0;i<n;i++){
        int a;
        cin>>a;
        vec.push_back(a);
	}

	for (int i=0;i<n;i++){
        int soma=0;
        for (int j=i;j<n+i;j++){
            soma += vec[j%n];
            if (soma>d){
                break;
            }
            else if (soma==d){
                aux++;
                break;
            }
        }
	}
	cout<<aux;
}
