//https://uva.onlinejudge.org/external/5/536.pdf
#include <iostream>
#include <string.h>
using namespace std;

char a[27],b[27];

void rt(int t,int r,int *qq,int *ww,bool *uu){

    if(t==r-1){

        cout << a[ww[t]];

    }
    else{

        if(ww[t+1]>ww[t]){

            for(int i=t-1;i>=0;i--){

                if(!uu[i] && ww[i]>ww[t]){

                    uu[i]=1;
                    cout << a[ww[i]];

                }
            }

            rt(t+1,r,qq,ww,uu);
            if(!uu[t]){

                cout << a[ww[t]];
                uu[t]=1;
            }
        }
        else{

            for(int i=t-1;i>=0;i--){

                if(!uu[i] && ww[i]>ww[t]){

                    uu[i]=1;
                    cout << a[ww[i]];

                }
            }

            cout << a[ww[t]];
            uu[t]=1;

            rt(t+1,r,qq,ww,uu);
        }
    }
}

int main(){

    int u;

    while(cin >> a >> b){

        int qq[27]={0};
        int ww[27]={0};
        bool uu[27]={0};

        u=0;

        int r=strlen(a);

        if(r==1){

            cout << a;
            continue;

        }

        while(u!=r){

            for(int i=0;i<r;i++){

                if(a[i]==b[u]){

                    qq[i]=u;
                    ww[u]=i;
                    break;

                }

            }

            u++;

        }

        rt(0,r,qq,ww,uu);

        cout << endl;

    }

    return 0;
}
