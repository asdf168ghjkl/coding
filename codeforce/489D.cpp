#include <iostream>
#include <stdio.h>
using namespace std;

bool rr[3005][3005];
long long r[3005];

int main(){

    int n,m,i,j,k;
    int s,e;
    long long to = 0;

    cin >> n >> m;

    for(i = 1;i <= m;i++){

        scanf("%d%d",&s,&e);

        rr[s][e] = 1;
    }

    for(i = 1;i <= n;i++){

        for(j = 1;j <= n;j++){

            r[j] = 0;
        }

        for(j = 1;j <= n;j++){

            if(rr[i][j]){

                for(k = 1;k <= n;k++){

                    if(k == i) continue;

                    if(rr[j][k]){

                        to += r[k];
                        r[k]++;

                    }
                }
            }
        }
    }

    cout << to;

    return 0;
}
