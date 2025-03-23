//OBI 2007 - Nivel 2

#include <bits/stdc++.h>

using namespace std;

int main(){
	int c, n;
	map<int,int> m;
	map<int,int> m2;

	cin>>c>>n;
	for (int i=0;i<c;i++){
        int a,b;
        cin>>a>>b;
        m[a]=b;
	}

	for (int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        if (m.find(a)!= m.end()){
            if (m[a]<b){
                m[a]=b;
                m2[a]=b;
                //cout<<a<<" "<<b;
            }
        }
        else {
            m[a]=b;
            m2[a]=b;
        }
	}
	auto ptr = m2.begin();
	for (int i=0;i<m2.size();i++){
            cout<<ptr->first<<" "<<ptr->second<<"\n";
            ptr++;
	}
}
