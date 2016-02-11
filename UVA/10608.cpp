#include <iostream>
#include <stack>
#include <stdio.h>
using namespace std;

bool used[30005] = {0};
int ma,mma;

void dfs(int c,stack<int> *f){

    int i;

    while(!f[c].empty()){

        i = f[c].top();
        f[c].pop();

        if(!used[i]){

            ma++;
            used[i] = 1;
            dfs(i,f);
        }
    }
}

int main(){

    int l;
    cin >> l;

    while(l--){

        int n,m,i,f1,f2;

        mma = 0;

        cin >> n >> m;

        stack <int> ff[n+1];

        for(i = 1;i <= m;i++){

            scanf("%d%d",&f1,&f2);

            ff[f1].push(f2);
            ff[f2].push(f1);
        }

        for(i = 1;i <= n;i++){

            if(!used[i] && !ff[i].empty()){

                ma = 1;
                used [i] = 1;
                dfs(i,ff);
                if(ma > mma) mma = ma;
            }
        }

        cout << mma << endl;

        for(i = 1;i <= n;i++) used[i] = 0;

    }
    return 0;
}
