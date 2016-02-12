//https://uva.onlinejudge.org/external/5/514.pdf
#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

int main(){

    int n=1,y,k=0;

    while(n){

        if(k==1)cout << endl;
        else k++;

        cin >> n;

        if(n==0) break;

        int b[n+1];
        int x;

        while (cin >> x && x!=0){

            b[1]=x;

            for(int i=2;i<=n;i++){

                cin >> b[i];

            }

            int bb=1,aa=1,z=0;
            stack <int> c;

            for(int i=1;i<=3*n;i++){

                z=0;
                y=0;
                if(!c.empty())z = (int) c.top();

                if(z==b[bb]){

                    bb++;
                    c.pop();
                    if(bb==n+1){

                        y=1;
                        break;

                    }

                }
                else if(aa==n+1){

                    break;

                }
                else{

                    c.push(aa);
                    aa++;

                }

            }

            if(y==1){

                cout << "Yes\n";

            }
            else cout << "No\n";

        }

    }

    return 0;

}

