#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

int main(){

    int n;

    cin >> n;

    char d;
    scanf("%c",&d);

    while(n--){

        long long *a1 = new long long [4];
        long long *a2 = new long long [4];
        long long *b1 = new long long [4];
        long long *b2 = new long long [4];

        a1[1]=0;
        a1[2]=1;
        a1[3]=1;

        a2[1]=1;
        a2[2]=1;
        a2[3]=0;

        while(1){

            scanf("%c",&d);

            if(d=='\n'){

                cout << a1[2] << '/' << a2[2] << endl;

                break;
            }

            if(d=='R'){

                b1[1]=a1[2];
                b1[2]=a1[2]+a1[3];
                b1[3]=a1[3];

                b2[1]=a2[2];
                b2[2]=a2[2]+a2[3];
                b2[3]=a2[3];

            }
            else{

                b1[1]=a1[1];
                b1[2]=a1[2]+a1[1];
                b1[3]=a1[2];

                b2[1]=a2[1];
                b2[2]=a2[2]+a2[1];
                b2[3]=a2[2];

            }

            swap(a1,b1);
            swap(a2,b2);

        }

        delete [] a1;
        delete [] a2;
        delete [] b1;
        delete [] b2;

    }

    return 0;

}
