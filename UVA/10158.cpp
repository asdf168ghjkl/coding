#include <iostream>
#include <stdio.h>
using namespace std;

int n;
int ff[20005];

int f(int x){

    if(ff[x] != x){

        return f(ff[x]);
    }
    else return x;
}


int main(){

    while(cin >> n){

        int c,l,r,a1,a2,b1,b2;

        for(int i = 0;i <= 2*n;i++){

            ff[i] = i;
        }

        while(scanf("%d%d%d",&c,&l,&r)){

            if (c == 0 && l == 0 && r == 0) break;

            a1 = f(l);
            a2 = f(l+n);
            b1 = f(r);
            b2 = f(r+n);

            switch(c){

                case 1:

                    if(a1 == b2) cout << -1 << endl;
                    else{

                        ff[a1] = b1;
                        ff[a2] = b2;
                    }
                    break;

                case 2:

                    if(a1 == b1) cout << -1 << endl;
                    else{

                        ff[a1] = b2;
                        ff[a2] = b1;
                    }
                    break;

                case 3:

                    if(a1 != b1) cout << 0 << endl;
                    else{

                        cout << 1 << endl;
                    }
                    break;

                case 4:

                    if(a1 != b2) cout << 0 << endl;
                    else{

                        cout << 1 << endl;
                    }
                    break;
            }
        }
    }

    return 0;
}
