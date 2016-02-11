#include <iostream>
#include <algorithm>
using namespace std;

struct work{

    double t;
    double f;
    int i;
    double a;

};

int main(){

    int n;
    bool m=0;
    cin  >> n;

    while(n--){

        if(m==1) cout << endl;
        else m++;

        int n1;

        cin >> n1;

        work a[n1+1];

        for(int i=1;i<=n1;i++){

            cin >> a[i].t >> a[i].f;

            a[i].i=i;

        }

        for(int i=1;i<n1;i++){

            for(int j=i;j<=n1;j++){

                if(a[i].t*a[j].f > a[j].t*a[i].f) swap(a[i],a[j]);

            }

        }

        for(int i=1;i<n1;i++){

            for(int j=i;j<=n1;j++){

                if(a[i].t*a[j].f == a[j].t*a[i].f && a[i].i>a[j].i){

                    swap(a[i],a[j]);

                }
                else if(a[i].t*a[j].f != a[j].t*a[i].f) break;

            }

        }

        cout << a[1].i;

        for(int i=2;i<=n1;i++){

            cout << ' ' << a[i].i;

        }

        cout << endl;

    }

    return 0;

}
