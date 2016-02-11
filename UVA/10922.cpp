#include<iostream>
#include<string.h>
using namespace std;

char x[1001];


int main(){

    int l,y,m;

    while(cin >> x){

        if(x[0]==48) break;

        y=0;

        int total=0,times=0;

        l=strlen(x);

        total=0;

        for(int i=0;i<l;i++){

                total+=x[i]-48;

            }

        while(total%9==0){

            times++;

            if(total==9) break;

            y=total;

            total=0;

            while(y!=0){

                total+=y%10;

                y/=10;

            }

        }

        if(times>0){

            cout << x << " is a multiple of 9 and has 9-degree " << times << "." << endl;

        }
        else{

            cout << x <<" is not a multiple of 9.\n";

        }



    }

    return 0;

}


