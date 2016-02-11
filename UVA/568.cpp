#include<iostream>
#include<iomanip>
using namespace std;

int main(){

    int x,y;

    while(cin >> x){

        y=1;

        for(int i=2;i<=x;i++){

            y*=i;

            while(y%10==0){

                y/=10;

            }

            while(y>99999){

                y-=100000;

            }

        }

        while(y>9){

            y-=10;

        }

        cout << setw(5) << x << " -> " << y << endl;

    }

}
