//https://uva.onlinejudge.org/external/2/291.pdf
#include<iostream>
#include<algorithm>
using namespace std;

int x[6][5]={0};
bool y[9]={0};
int z[6][5]={0};
int k[6]={0};
int rou[9]={0};
int ans[9]={0};

void per(int n,int s){

    for(int i=1;i<=k[n];i++){

        if(!y[z[n][i]]){

            y[z[n][i]]=1;
            ans[s]=x[n][i];
            rou[s]=z[n][i];

            if(s==8){

                for(int j=0;j<=8;j++){

                    cout << ans[j];

                }

                cout << endl;

            }
            else{

                per(ans[s],s+1);

            }

        }

    }
    fill(y+1,y+9,0);
    for(int j=1;j<s-1;j++){

        y[rou[j]]=true;

    }
}

int main(){

    x[1][1]=2;
    x[1][2]=3;
    x[1][3]=5;

    z[1][1]=1;
    z[1][2]=2;
    z[1][3]=3;

    k[1]=3;


    x[2][1]=1;
    x[2][2]=3;
    x[2][3]=5;

    z[2][1]=1;
    z[2][2]=5;
    z[2][3]=4;

    k[2]=3;


    x[3][1]=1;
    x[3][2]=2;
    x[3][3]=4;
    x[3][4]=5;

    z[3][1]=2;
    z[3][2]=5;
    z[3][3]=7;
    z[3][4]=6;

    k[3]=4;


    x[4][1]=3;
    x[4][2]=5;

    z[4][1]=7;
    z[4][2]=8;

    k[4]=2;


    x[5][1]=1;
    x[5][2]=2;
    x[5][3]=3;
    x[5][4]=4;

    z[5][1]=3;
    z[5][2]=4;
    z[5][3]=6;
    z[5][4]=8;

    k[5]=4;

    ans[0]=1;

    per(1,1);


    return 0;

}

