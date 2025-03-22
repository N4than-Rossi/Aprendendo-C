//OBI 2010 - Nivel 1

#include <bits/stdc++.h>
#include <stdio.h>

using namespace std;

int main(){
	int n,t;
	priority_queue <pair<int,string>> pq;//ordenar por nivel
    vector<priority_queue<string,vector<string>,greater<string>>> pq2; //vetor dinamico que organiza os times por nomes

	cin>>n>>t;

	for (int i=0;i<n;i++){ //puxa o nome e nivel de cada jogador
        string a;
        int b;
        cin>>a>>b;
        pq.push({b,a});
	}
	for (int i=0;i<n;i++){
        if (i<t){
            pq2.push_back(priority_queue<string,vector<string>,greater<string>>());
            //cria filas de prioridade por cada time

        }
        pq2[i%t].push(pq.top().second);//distribuindo os jogadores pelos times
        pq.pop();

	}
	for (int i=0;i<t;i++){ //imprimindo tudo

        cout << "Time " << i+1 <<endl;
        while (pq2[i].size()!=0){
            cout<<pq2[i].top()<<endl;
        pq2[i].pop();
        }
        cout << endl;

	}
}
