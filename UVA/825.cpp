#include<iostream>
#include<sstream>
using namespace std;

int main(){

    int n;
    cin >> n;

    for(int i=1;i<=n;i++){

        int x,y;

        cin >> x >> y;

        int sq[100][100]={0};
        bool ep[100][100]={0};

        cin.ignore();
        string str;

        for(int j=1,k;j<=x;j++){

            getline(cin,str);
            stringstream ss(str);
            ss >> k;

            while(ss >> k)
                ep[j][k]=true;

        }

        sq[1][1]=1;

        for(int j=1;j<=x;j++){

            for(int k=1;k<=y;k++){

                if(ep[j][k]) continue;
                if(j>1) sq[j][k]+=sq[j-1][k];
                if(k>1) sq[j][k]+=sq[j][k-1];

            }

        }

        cout << sq[x][y] << endl ;

        if(i!=n) cout << endl;

    }

    return 0;

}
