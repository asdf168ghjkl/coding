#include <iostream>
using namespace std;

long long f[5003] = {0} ,ff[5003];

int main(){

    int n,a,b,k,i,j,m,mi;
    long long to = 0,ma;

    cin >> n >> a >> b >> k;

    bool nn = b % 2 ;

    f[a] = 1;

    if( (a-b == 1)|| (b-a == 1) ){

        cout << 0;
    }
    else if(a < b){

        for(i = 1;i <= k;i++){

            nn = b % 2 ;

            for(j = 1;j < b;j++){

                ff[j] = 0;
            }

            for(j = 1;j <= b/2;j++){

                ff[1] += f[j];
            }

            mi = j;
            ma = ff[1];

            for(j = 2;j < b;j++){

                if(nn){

                    nn = 0;
                    ma += f[mi];
                    mi++;
                }
                else{

                    nn = 1;
                }

                ff[j] = ma;
            }

            for(m = 1;m < b;m++){

                ff[m] -= f[m];

                f[m] = ff[m];

                if( f[m] != 0 && f[m] % 1000000007 == 0) f[m] = 1000000007;
                else f[m] %= 1000000007;
            }
        }

        for(m = 1;m < b;m++){

            to += f[m];

            if(to > 1000000007)  to -= 1000000007;
        }

        cout << to;
    }
    else{

        for(i = 1;i <= k;i++){

            nn = (b+n+1) % 2;

            for(j = b+1;j <= n;j++){

                ff[j] = 0;
            }

            for(j = n;j > (n+b) / 2;j--){

                ff[n] += f[j];
            }

            mi = j;
            ma = ff[n];

            for(j = n-1;j > b;j--){

                if(nn){

                    nn = 0;
                    ma += f[mi];
                    mi--;
                }
                else{

                    nn = 1;
                }

                ff[j] = ma;
            }

            for(m = b+1;m <= n;m++){

                ff[m] -= f[m];

                f[m] = ff[m];

                if( f[m] != 0 && f[m] % 1000000007 == 0) f[m] = 1000000007;
                else f[m] %= 1000000007;
            }
        }

        for(m = b+1;m <= n;m++){

            to += f[m];
            if(to > 1000000007) to -= 1000000007;
        }

        cout << to;
    }

    return 0;
}
