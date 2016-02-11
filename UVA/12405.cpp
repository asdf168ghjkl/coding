#include <iostream>

using namespace std;

#define QAQ cin

int main()
{
    int t,i,j;

    QAQ >> t;

    for(j = 1;j <= t;j++){

        int n;

        QAQ >> n;

        char g[n+1];
        bool gg[n+1];

        for(i = 1;i <= n;i++){

            QAQ >> g[i];

            g[i] == '.' ? gg[i] = 1 : gg[i] = 0;
        }

        int c = 0;

        for(i = 1;i <= n;i++){

            if(gg[i] == 1){

                gg[i] = 0;
                gg[i+1] = 0;
                gg[i+2] = 0;
                c++;
            }
        }

        cout << "Case " << j << ": " << c << endl;
    }

    return 0;
}
