#include <iostream>
#include <stack>
using namespace std;

bool x[105];
stack <int> tt[105];
bool yy = 0;

void dd(int c){

    int i;

    while(!tt[c].empty()){

        i = tt[c].top();
        tt[c].pop();

        if(!x[i]){

            x[i] = 1;
            dd(i);
        }
    }

    !yy ? yy = 1 : cout << " ";
    cout << c;
}

int main(){

    int n,m;

    while(cin >> n >> m, n||m){

        int i,j;
        yy = 0;

        for(i = 1;i <= n;i++) x[i] = 0;

        for(i = 1;i <= m;i++){

            int le,ri;

            cin >> le >> ri;

            tt[ri].push(le);
        }

        for(j = n;j >= 1;j--){

            if(tt[j].empty() && !x[j]){

                x[j] = 1;
                !yy ? yy = 1 : cout << " ";
                cout << j;
            }

            if(!tt[j].empty() && !x[j]){

                x[j] = 1;
                dd(j);
            }
        }
        cout << endl;
    }
    return 0;
}
