// exercício de Estrutura de dados - set <int>

#include <bits/stdc++.h>

using namespace std;

int main(){
	//st.insert(1);
	//st.find(10);
	int a,b,aux1=0,aux2=0;;
	cin>>a>>b;
	set<int> s1;
	set<int> s2;

	for (int i=0;i<a;i++){
        int n;
        cin>>n;
        s1.insert(n);
        }

    for (int i=0;i<b;i++){
        int n;
        cin>>n;
        s2.insert(n);

        }

    auto p1 = s1.begin();
    auto p2 = s2.begin();
	for (int i=0;i<max(s2.size(),s1.size());i++){
        if (p1 != s1.end()){
            if (s2.find(*p1)== s2.end()){
                aux1++;
            }
            p1++;
        }
        if (p2 != s2.end()){
            if (s1.find(*p2)== s1.end()){
                aux2++;
            }
            p2++;
        }

	}
	cout<<min(aux1,aux2);
}

