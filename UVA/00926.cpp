#include<iostream>
#include<sstream>
using namespace std;

int main(){

    int n,stx,sty,edx,edy,w,px,py;
    char d;

    while(cin >> n){

        for(int i=1;i<=n;i++){

            int x;

            cin >> x >> stx >> sty >> edx >> edy >> w;

            unsigned long long sq[33][33]={0};
            bool ep[33][33][2]={0};

            sq[stx][sty]=1;

            for(int j=1;j<=w;j++){

                cin >> px >> py >> d;

                switch(d-64){

                    case 14://N

                        ep[px][py+1][0]=true;
                        break;

                    case 19://S

                        ep[px][py][0]=true;
                        break;

                    case 5://E

                        ep[px+1][py][1]=true;
                        break;

                    case 23://W

                        ep[px][py][1]=true;
                        break;

                }

            }

            for(int j=stx;j<=edx;j++){

                for(int k=sty;k<=edy;k++){

                    if(j>stx && !ep[j][k][1]) sq[j][k]+=sq[j-1][k];
                    if(k>sty && !ep[j][k][0]) sq[j][k]+=sq[j][k-1];

                }

            }

            cout << sq[edx][edy] << endl ;

        }

    }

    return 0;

}

