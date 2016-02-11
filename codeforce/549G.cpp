#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;

struct gg{

    int m1;
    int m2;
    int po;

}m[200001];

bool cmp(gg a,gg b){

    return a.m2 < b.m2;
}

int main(){

    int n,i,j;
    bool k=0;

    scanf("%d",&n);

    for(i = 1;i <= n;i++){

        scanf("%d",&m[i].m1);
        m[i].m2 = m[i].m1;
        m[i].po = i;
    }

    for(i = n-1,j = 1;i >= 1;i--,j++){

        m[i].m2 -= j;
    }

    sort(m+1,m+1+n,cmp);

    for(i = 1;i <= n;i++){

        m[i].m1 += (m[i].po-i);

        if(m[i].m1 < 0){

            k = 1;
            break;
        }
    }

    if(!k){

        for(i = 1;i < n;i++){

            if(m[i].m1 > m[i+1].m1){

                k = 1;
                break;
            }
        }
    }

    if(k){

        printf(":(\n");
    }
    else{

        printf("%d",m[1].m1);

        for(i = 2;i <= n;i++){

            printf(" %d",m[i].m1);
        }

        printf("\n");
    }


    return 0;
}
