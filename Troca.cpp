//OBI 2018 - Nivel 1 - 3ª fase

#include <bits/stdc++.h>

using namespace std;

int main() {
    int n,m;
    cin >> n >> m;
    vector<int> v1(n), v2(n), troca(n+1,0);
    for (int i = 0; i < n;i++){
        cin >> v1[i];
    }
    for (int i = 0; i < n;i++){
        cin >> v2[i];
    }

    for (int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        a--; b--;
        troca[a]++;
        troca[b+1]++;
    }

    int index = 0;
    for (int i=0;i<n;i++){
        index += troca[i];
        if (index % 2 == 0){
            cout << v1[i] << " ";
        }
        else {
            cout << v2[i] << " ";
        }
    }
    
    return 0;
}
