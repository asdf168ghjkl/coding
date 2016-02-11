#include <iostream>
using namespace std;

int main(){

    int n,d,r;

    while(cin >> n >> d >> r){

        if(n==0 && d==0 && r==0) break;

        int a[n+1],b[n+1],c[n+1],x=0;

        for(int i=1;i<=n;i++){

            cin >> a[i];

        }

        for(int i=1;i<=n;i++){

            cin >> b[i];

        }

        for(int i=1;i<n;i++){

            for(int j=i+1;j<=n;j++){

                if(a[i]>a[j]){

                    a[i]+=a[j];
                    a[j]=a[i]-a[j];
                    a[i]-=a[j];

                }

                if(b[i]<b[j]){

                    b[i]+=b[j];
                    b[j]=b[i]-b[j];
                    b[i]-=b[j];

                }

            }

        }

        for(int i=1;i<=n;i++){

            c[i]=a[i]+b[i];
            if(c[i]>d){

                x+=(c[i]-d)*r;

            }

        }

        cout << x << endl;

    }

    return 0;

}
