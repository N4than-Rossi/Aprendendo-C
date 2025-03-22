//OBI 2010 - Nivel Junior

#include <stdio.h>

int main(){
   int x, y=0;
   scanf("%d", &x);
   int m[x][2];

   for (int i=0;i<x;i++){
    for (int I=0;I<2;I++){
        scanf("%d", &m[i][I]);
    }
   }

   for (int i=0;i<x;i++){
        if(m[i][0]>m[i][1]){
         y = y+ m[i][1];
        }
   } printf("%d", y);
}
