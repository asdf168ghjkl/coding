//https://uva.onlinejudge.org/external/5/572.pdf
#include <iostream>
using namespace std;

int m,n;
int oil[105][105];
int hor[9] = {0,-1,0,1,-1,1,-1,0,1};
int ver[9] = {0,-1,-1,-1,0,0,1,1,1};

void dfs(int x,int y){

    for(int i = 1;i <= 8;i++){

        if(oil[ x + ver[i] ][ y + hor[i] ] == 1){

            oil[ x + ver[i] ][ y + hor[i] ] = 0;
            dfs(x + ver[i],y + hor[i]);
        }
    }
}

int main(){

    int i,j;

    while(cin >> m >> n, m&&n){

        char c;
        int num = 0;

        for(i = 1;i <= m;i++){

            for(j = 1;j <= n;j++){

                cin >> c;

                c == '*' ? oil[i][j] = 0 : oil[i][j] = 1;
            }
        }

        for(i = 1;i <= m;i++){

            for(j = 1;j <= n;j++){

                if(oil[i][j] == 1){

                    num++;
                    oil[i][j] = 0;
                    dfs(i,j);
                }
            }
        }

        cout << num << endl;

    }
}
