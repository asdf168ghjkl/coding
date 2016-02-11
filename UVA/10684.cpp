#include <iostream>

using namespace std;

int main()
{
    int t,i,j;

    while(cin >> t,t != 0){

        int b[t+1],ma = 0;

        for(i = 1;i <= t;i++){

            cin >> b[i];
        }

        int to = 0;

        for(j = 1;j <= t;j++){

            to += b[j];

            if(to > ma) ma = to;

            if(to < 0) to = 0;
        }

        if(!ma){

            cout << "Losing streak.\n";
        }
        else{

            cout << "The maximum winning streak is " << ma << ".\n";
        }
    }

    return 0;
}
