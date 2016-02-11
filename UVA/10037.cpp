#include <iostream>
#include <algorithm>
using namespace std;

int main(){

    int n;
    bool z=0;

    cin >> n;

    while(n--){

        if(z) cout << endl;
        else z=1;

        bool a[1000]={0};

        int x,x1,sec=0,y=0;

        cin >> x1;

        int p[x1+1];

        x=x1;

        for(int i=1;i<=x;i++){

            cin >> p[i];

        }

        if(x1==1){

            cout << p[1] << endl;
            cout << p[1] << endl;
            continue;

        }

        sort(p+1,p+x+1);

        while(x>=4){

            y++;

            if(2*p[2]<=p[1]+p[x-1]){

                sec+=p[1]+2*p[2]+0*p[x-1]+p[x];


            }
            else{

                sec+=2*p[1]+0*p[2]+p[x-1]+p[x];
                a[y]=1;

            }

            x-=2;

        }

        if(x==3){

            sec+=p[1]+p[2]+p[3];

        }
        else{

            sec+=p[2];

        }

        x=x1;

        cout << sec << endl;

        for(int i=1;i<=y;i++){

            if(a[i]==0){

                cout << p[1] << ' ' << p[2] << endl;
                cout << p[1] << endl;
                cout << p[x-1] << ' ' << p[x] << endl;
                cout << p[2] << endl;

            }
            else{

                cout << p[1] << ' ' << p[x-1] << endl;
                cout << p[1] << endl;
                cout << p[1] << ' ' << p[x] << endl;
                cout << p[1] << endl;

            }

            x-=2;

        }

        if(x==3){

            cout << p[1] << ' ' << p[3] << endl;
            cout << p[1] << endl;
            cout << p[1] << ' ' << p[2] << endl;

        }
        else{

            cout << p[1] << ' ' << p[2] << endl;

        }

    }

    return 0;
}
