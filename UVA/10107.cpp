#include <iostream>
using namespace std;

int main(){

    int num,sq[10000]={0},n=0,m=1,i;

    while(cin >> num){

        n++;

        for(i=1;i<=n-1;i++){

            if((num<sq[i])||(sq[i]==0)){

                m=i;

            }

        }

        for(i=n-1;i>=m;i--){

            sq[i+1]=sq[i];

        }

        sq[m]=num;

        if(n%2==0){

            cout << (sq[n/2]+sq[n/2+1])/2 << endl;

        }
        else{

            cout << sq[(n+1)/2] << endl;

        }

    }

    return 0;

}
