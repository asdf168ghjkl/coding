#include <iostream>
#include <algorithm>
#include <math.h>
#include <stdio.h>
using namespace std;

struct bb{

    long long le;
    int o;
};

struct is{

    long long l;
    long long s;
    long long r;
    long long la;
    int a;
    short o;
};

struct cc{

    long long le;
    int num;
    int in;
    int en;
};

bool cmp1(bb a, bb b){

    return a.le < b.le;
}

bool cmp2(is a, is b){

    return a.r < b.r;
}

bool cmp3(is a, is b){

    return a.o < b.o;
}

is a[200010];
bb b[200010];
cc c[200010];
int n,m,cur = 0,d[200010];
long long x[200010];
bool used[200010],aa=0;

void check(int cu){

    long long l = a[cu].l;
    long long s = a[cu].s;

    int mid = lower_bound(x+1,x+1+cur,s)-x;

    for(int i = mid;c[i].le <= l && i <= m;i++){

        if(c[i].le == a[cu].la) continue;

        if(c[i].le < s) continue;

        if(c[i].in > c[i].en) continue;

        if(!used[c[i].in]){

            d[a[cu].o] = b[c[i].in].o;
            used[c[i].in] = true;
            c[i].in++;

            if(cu == n-1){

                aa = 1;
                return;
            }
            else{

                check(cu+1);

                if(aa) return;

                used[i] = false;
                a[cu].la = b[i].le;
                c[i].in--;
            }
        }
    }
}

int main(){

    int i;

    scanf("%d%d",&n,&m);

    long long t,tt,r,rr,mm = 0;

    scanf("%I64d%I64d",&t,&r);

    for(i = 1;i < n;i++){

        scanf("%I64d%I64d",&tt,&rr);

        a[i].l = rr-t;
        a[i].s = tt-r;
        a[i].r = rr-tt+r-t;
        a[i].la = 0;
        a[i].o = i;
        t = tt;
        r = rr;
    }

    for(i = 1;i <= m;i++){

        scanf("%I64d",&b[i].le);
        b[i].o = i;
    }

    sort(b+1,b+m+1,cmp1);

    sort(a+1,a+n,cmp2);

    for(i = 1;i <= m;i++){

        if(b[i].le == mm){

            c[cur].num++;
        }
        else{

            mm = b[i].le;
            c[cur++].en = i-1;
            c[cur].in = i;
            c[cur].num = 1;
            c[cur].le = mm;
        }
    }

    c[cur].en = m;

    for(i = 1;i <= cur;i++){

        x[i] = c[i].le;
    }

    check(1);

    if(aa){

        printf("Yes\n%d",d[1]);

        for(i = 2;i < n;i++){

            printf(" %d",d[i]);
        }
    }
    else{

        cout << "No\n";
    }

    return 0;
}
