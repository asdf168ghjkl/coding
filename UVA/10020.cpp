#include<iostream>
#include<queue>
using namespace std;

struct se{

    int L,R;

}a[100003];

struct bb{

    int ma;
    int od;

}b[60000];

bool cmp(se a, se b){

    return a.R > b.R;
}

int main(){

    int x,i,j,t1,t2,t3 = 0,t4;
    queue <int> c;

    cin >> x;

    while(x--){

        for(i = 0;i <= 55000;i++){

            b[i].ma = 0;
        }

        t1 = 0;
        t2 = 0;
        t4 = 0;

        int an;

        cin >> an;

        int ll,rr;

        while(cin >> ll >> rr){

            if(ll==0 && rr==0) break;

            t1++;
            a[t1].L=ll;
            a[t1].R=rr;

            if(ll < 0) ll = 0;

            for(j = ll;j <= rr;j++){

                if(j > an) break;

                if(b[j].ma < rr){

                    b[j].ma = rr;
                    b[j].od = t1;
                }
            }
        }

        while(t4 < an){

            if(b[t4].ma <= 0) break;

            c.push(b[t4].od);
            t4 = b[t4].ma;
            t2 ++;
        }

        if(t3) cout << endl;

        t3 = 1;

        if(t4 >= an){

            cout << t2 << endl;

            for(int i = 1;i <= t2;i++){

                j = c.front();
                c.pop();

                cout << a[j].L << ' ' << a[j].R << endl;
            }
        }
        else{

            cout << 0 << endl;
        }
    }

    return 0;
}
