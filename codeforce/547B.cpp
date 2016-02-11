#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;

int a[200000];


int main(){

   int n,i,j,k,ma,m1,m2,o1,m;
   scanf("%d",&n);

   for(i = 1;i <= n;i++){

        scanf("%d",&a[i]);
   }

   for(i = 0;i < n;i++){

        bool pp = 1;

        while(pp && i){

            m1 = m2 = 0;

            for(j = 1;j <= n;j++){

                if(a[j] > m1) m1 = a[j];
            }

            for(j = 1;j <= n;j++){

                if(a[j] > m2 && a[j] != m1) m2 =a[j];
            }

            for(j = 1;j <= n;j++){

                if(a[j] == m1){

                    o1 = j-1;
                    j++;

                    for(;a[j] == m1;j++);

                    if(j - o1 - 2 >= i){

                        pp = 0;
                        continue;
                    }

                    a[j] > a[o1] ? m = a[j] : m = a[o1];

                    if(m == m2) pp = 0;

                    for(k = o1+1;k < j;k++) a[k] = m;
                }
            }
        }

        ma = 0;

        for(k = 1;k <= n;k++){

            if(a[k] > ma) ma = a[k];
        }

        printf("%d ",ma);
   }

   return 0;
}
