#include<iostream>
using namespace std;

int main(){

    int n,m,z;

    while(cin >> n >> m){

        if(n==0 && m==0) break;

        if(m>n/2) z=n-m;
        else z=m;

        int y=1;

        unsigned long long x=1;

        for(int i=n-z+1;i<=n;i++){

            x*=i;

            if(y<=z && x%y==0){

                x/=y;
                y++;

            }

        }

        cout << n << " things taken " << m << " at a time is " << x << " exactly.\n";

    }

    return 0;

}
