//OBI 2014 - Nivel Junior

#include <bits/stdc++.h>
//#include <vector>
using namespace std;
int a[50001],b[100001];
int main(){
    int N,M,aux;
    scanf("%d",&N);
    for (int i=0;i<N;i++){
        scanf("%d",&a[i]);
    }

    for (int i=0;i<100001;i++){b[i]=1;}
    scanf("%d",&M);
    for (int i=0;i<M;i++){
        scanf("%d",&aux);
        b[aux]=0;
    }
    for (int i=0,cu=1;i<N;i++){
        if (b[a[i]]){
            if (cu){
                printf("%d",a[i]);
                cu=0;
            }
            else {printf(" %d",a[i]);}
        }
    }
	return 0;
}
