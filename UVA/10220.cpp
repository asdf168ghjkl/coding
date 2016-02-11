#include<iostream>
#include<iomanip>
using namespace std;

int main(){

    int x,i,j,k;

    while(cin >> x){

        long long num[1001]={0};
        int up[1002]={0},total=0;

        num[1]=1;

        j=1;

        for(i=1;i<=x;i++){

            for(k=1;k<=j;k++){

                *(num+k)=*(num+k)*i;

                if(*(num+k)>99999999){

                    *(up+k+1)=*(num+k)/100000000;
                    *(num+k)=*(num+k)%100000000;
                    if(j==k) j++;

                }
                else *(up+k+1)=0;

                *(num+k)+=*(up+k);

            }

        }

        for(i=1;i<=j;i++){

            while(*(num+i)!=0){

                total+=*(num+i)%10;
                *(num+i)/=10;

            }

        }

        cout << total << endl;

    }

    return 0;

}

