#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;

int minee=2147483600,en;
int n,to=0;
int cc[201]={0};

struct aa{

    int l;
    int e;

}kk[100003];

bool cmp(aa l1, aa l2){

    return l1.l < l2.l;
}

int main(){

    int i,j,u;

    scanf("%d",&n);

    for(i=1;i<=n;i++)
        scanf("%d",&kk[i].l);

    for(i=1;i<=n;i++)
        scanf("%d",&kk[i].e),to+=kk[i].e;

    sort(kk+1,kk+n+1,cmp);

    en=to;

    i=1;

    while(i<=n){

        for(j=i;kk[i].l==kk[j].l;++j){

            en-=kk[j].e;

        }

        j=j-i-1;

        for(u=200;u>=1;u--){

            if(cc[u]<=j){

                en-=u*cc[u];
                j-=cc[u];
            }
            else{

                en-=u*j;
                break;
            }

            if(!j) break;
        }

        if(en < minee){

            minee=en;
        }

        for(j=i;kk[i].l==kk[j].l;j++){

            cc[kk[j].e]++;
        }
        i=j;
        en=to;
    }

    cout << minee << endl;


    return 0;
}
