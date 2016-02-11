#include <iostream>
using namespace std;

struct tt{

    int t1;
    int t2;

};

int main(){

    int n;

    while(cin >> n){

        int x1=1000,x2=1000,y1,y2,bb=0,cc=0,total=1;

        tt a[n+1],d[n+1];
        int b[n+1],c[n+1];

        for(int i=1;i<=n;i++){

            cin >> a[i].t1;
            d[i].t1=a[i].t1;
            total+=a[i].t1;
        }
        for(int i=1;i<=n;i++){

            cin >> a[i].t2;
            d[i].t2=a[i].t2;
            total+=a[i].t2;
        }
        for(int i=1;i<=n;i++){

            x1=1000;
            x2=1000;

            for(int j=1;j<=n;j++){

                if(d[j].t1==1000) continue;

                if(d[j].t1>d[j].t2){

                    if(d[j].t2 < x2){

                        x2=d[j].t2;
                        y2=j;
                    }
                }
                else{

                    if(d[j].t1 < x1){

                        x1=d[j].t1;
                        y1=j;
                    }
                }
            }

            if(x1 > x2){

                cc++;
                c[cc]=y2;
                d[y2].t1=1000;
                d[y2].t2=1000;
            }
            else{

                bb++;
                b[bb]=y1;
                d[y1].t1=1000;
                d[y1].t2=1000;
            }
        }

        int time1=0,time2=0;

        if(bb!=0) time2=a[b[1]].t1;
        else time2=a[c[1]].t1;

        for(int i=1;i<=bb;i++){

            time1+=a[b[i]].t1;
            if(time2 < time1){

                time2 = time1 + a[b[i]].t2;

            }
            else{

                time2 += a[b[i]].t2;

            }

        }

        for(int i=cc;i>=1;i--){

            time1+=a[c[i]].t1;
            if(time2 < time1){

                time2 = time1 + a[c[i]].t2;

            }
            else{

                time2 += a[c[i]].t2;

            }

        }

        cout << time2 << endl;

    }

    return 0;
}
