#include <iostream>
#include<stdio.h>
using namespace std;

int main(){

    long long x,y,mi,t=0;

    while(cin >> x >> y ){

        if(x<0&&y<0) break;

        t++;
        mi=x;

        int k=1;

        while(mi!=1){

            if(mi%2==0){

                mi/=2;
            }
            else{

                mi=3*mi+1;

                if(mi>y) break;
            }
            k++;
        }

    	cout << "Case " << t << ": A = " << x << ", limit = " << y << ", number of terms = " << k << endl;
    }
    return 0;
}

