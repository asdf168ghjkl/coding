#include <iostream>
#include <stack>
#include <algorithm>
#include <queue>
using namespace std;

int n;
bool used[100005];

struct qq{

    int t,d,l;

}q[100005];

struct rr{

    long long ll;
    int root;
    int cc;

}ro[100005];

struct cmp{

    bool operator()(rr a, rr b){

        return a.ll > b.ll;
    }
};

priority_queue< rr, vector<rr> , cmp > nn;
stack <rr> r[100005];
stack <int> ans;

void dfs(int cc){

    int i;

    while( !r[cc].empty() ){

        i = r[cc].top().root;

        if( (!used[i]) && (!ro[i].ll || ro[i].ll > r[cc].top().ll + ro[cc].ll) ){

            ro[i].ll = r[cc].top().ll + ro[cc].ll;
            ro[i].root = cc;
            nn.push(ro[i]);
        }

        r[cc].pop();
    }
}

bool cmp1(qq a, qq b){

    return a.t < b.t;
}

bool cmp2(qq a, qq b){

    return (a.t == b.t)&&(a.d < b.d);
}

bool cmp3(qq a, qq b){

    return (a.t == b.t)&&(a.d == b.d)&&(a.l < b.l);
}

int main(){

    int s,e,m,i,l,j;

    cin >> n >> m;

    for(i = 1;i <= m;i++){

        cin >> s >> e >> l;
        if(s > e) swap(s,e);

        q[i].t = s;
        q[i].d = e;
        q[i].l = l;
    }

    sort(q+1,q+1+m,cmp1);
    sort(q+1,q+1+m,cmp2);
    sort(q+1,q+1+m,cmp3);

    for(i = 1;i < m;i++){

        for(j = i+1;j <= m;j++){

            if( (q[i].d == q[j].d) && (q[i].t == q[j].t) ){

                q[j].t = 0;
            }
            else break;
        }

        i = j-1;
    }

    for(i = 1;i <= m;i++){

        rr tmp;

        if(q[i].t){

            tmp.ll = q[i].l;
            tmp.root = q[i].d;

            r[q[i].t].push(tmp);

            tmp.root = q[i].t;

            r[q[i].d].push(tmp);
        }
    }

    used[1] = 1;

    for(i = 1;i <= n;i++){

        ro[i].cc = i;
    }

    while( !r[1].empty() ){

        i = r[1].top().root;
        ro[i].ll =  r[1].top().ll;
        ro[i].root = 1;
        r[1].pop();

        nn.push(ro[i]);
    }

    while(!nn.empty()){

        i = nn.top().cc;
        nn.pop();
        used[i] = 1;

        if(i != n) dfs(i);
    }

    if(!ro[n].root){

        cout << -1;
    }
    else{

        int aa = n;
        ans.push(n);

        while(aa != 1){

            aa = ro[aa].root;
            ans.push(aa);
        }

        while(!ans.empty()){

            cout << ans.top() << " ";
            ans.pop();
        }
    }
    return 0;
}
