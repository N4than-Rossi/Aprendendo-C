//OBI 2018 - Nivel 1 - 3ª fase
//feito com backtracking

#include <bits/stdc++.h>
using namespace std;
int r,k;

int func(int restante, int base, int qnt){
    if (qnt == 0 && restante == 0) return 1;
    if (qnt==0) return 0;
    if (base > restante) return 0;
    
    int ans=0;
    for (int i = base; i <= r; i++){
        ans += func(restante-i, i+1, qnt-1);
    }
    return ans;
}

int main() {
    cin >> r >> k;
    cout << func(r,1,k);
    return 0;
}
