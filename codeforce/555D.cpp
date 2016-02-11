#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <math.h>
using namespace std;

pair<int, int> peg[200005];

int main(){

    int n,m,i,a,l,z,mid,k,len;

    scanf("%d%d",&n,&m);

    int x[n+1],pos[n+1];

    for(i=1;i<=n;i++){

        scanf("%d",&peg[i].first);
        peg[i].second = i;
    }

    sort(peg+1,peg+n+1);

    for(i=1;i<=n;i++){

        pos[peg[i].second] = i;
        x[i] = peg[i].first;
    }

    for(i=1;i<=m;i++){

        scanf("%d%d",&a,&l);

        k = 0;

        a = pos[a];

        mid = upper_bound(x+1,x+n+1,x[a]+l)-x-1;

        l -= abs(x[mid] - x[a]);

        a = mid;

        while(1){

            if(k == 1){

                z = x[a]+l;
                mid = upper_bound(x+1,x+n+1,z)-x-1;
            }
            else{

                z = peg[a].first-l;
                mid = lower_bound(x+1,x+n+1,z)-x;
            }

            if(mid == a) break;

            len = abs(x[mid] - x[a]);

            if((l/len)%2 == 1){

                k = !k;
                a = mid;
            }

            l %= len;
        }

        printf("%d\n",peg[a].second);
    }

    return 0;
}
