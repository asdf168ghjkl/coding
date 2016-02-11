#include <iostream>
using namespace std;

int main(){

    int x,y,z;

    int n;

    cin >> n;

    while(n--){

        cin >> x >> y >> z;

        int e=x+y;
        int ans=0;

        while(e>=z){

            ans+=e/z;

            e=e%z+e/z;

        }

        cout << ans << endl;


    }

    return 0;

}
