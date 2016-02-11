#include <iostream>

using namespace std;

int main()
{
    int n,i,j,k,ma = -2147483600;

    while(cin >> n){

        int num[n+1][n+1];

        for(i = 1;i <= n;i++){

            for(j = 1;j <= n;j++){

                cin >> num[i][j];
            }
        }

        for(j = 1;j <= n;j++){

            int tmp = 0;

            for(k = 1;k <= n;k++){

                tmp += num[k][j];

                if(tmp > ma) ma = tmp;

                if(tmp < 0) tmp = 0;

            }
        }

        for(i = 2;i <= n;i++){

            for(j = i-1;j >= 1;j--){

                for(k = 1;k <= n;k++){

                    num[k][j] += num[k][i];
                }
            }

            for(j = 1;j <= n;j++){

                int tmp = 0;

                for(k = 1;k <= n;k++){

                    tmp += num[k][j];

                    if(tmp > ma) ma = tmp;

                    if(tmp < 0) tmp = 0;

                }
            }
        }

        cout << ma << endl;

    }

    return 0;
}
