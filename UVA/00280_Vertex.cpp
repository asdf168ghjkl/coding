//https://uva.onlinejudge.org/external/2/280.pdf
#include<iostream>
using namespace std;

short x[101][101],in[101],n;

void DFS(int i){

    for(int k=1;k<=n;k++){

        if(x[i][k]==1&&in[k]==0){

            in[k]=1;

            DFS(k);

        }

    }

}

int main(){

    int i,j;

    while(cin >> n&&n!=0){

        int y,z,q,qu;

        for(i=1;i<=n;i++){

            for(j=1;j<=n;j++){

                x[i][j]=0;

            }

        }

        while(cin >> y&&y!=0){

            while(cin >> z&&z!=0){

                x[y][z]=1;

            }

        }

        cin >> q;

        for(i=1;i<=q;i++){

            int t1=0,t2=0;

            for(j=1;j<=n;j++) in[j]=0;

            cin >> qu;

            DFS(qu);

            for(j=1;j<=n;j++){

                if(in[j]==0){

                    t1++;

                }

            }

            if(t1==0){

                cout << 0 << endl;

            }
            else{

                cout << t1 << ' ';

                for(j=1;j<=n;j++){

                    if(in[j]==0){

                        t2++;

                        cout << j;

                        if(t2==t1){

                            cout << endl;

                            break;

                        }
                        else{

                            cout << ' ';

                        }

                    }

                }

            }

        }

    }

    return 0;

}

