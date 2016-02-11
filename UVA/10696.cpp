#include <iostream>
using namespace std;

int main(){

    int x;

    while(cin >> x,x){

        if(x>=101){

            cout << "f91(" << x << ") = " << x-10 << endl;

        }
        else{

            cout << "f91(" << x << ") = " << 91 << endl;

        }

    }

    return 0;

}
