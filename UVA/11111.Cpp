#include <iostream>
#include <sstream>
#include <stdio.h>
using namespace std;

int main(){

    string x;
    int ans=0;

    while(getline(cin,x)){

        ans=0;

        stringstream p(x);

        int z[100000]={0},zz=1,yy=0,xx=1;
        int y[100000]={0};
        int k[100000]={0};
        int m[100000]={0};
        int q[100000]={0},qq=1;
        int po=0,ne=0;

        while(p >> z[zz]){

            zz++;
        }

        zz--;

        int i=1;

        if(zz==0){

            cout << ":-) Matrioshka!\n";
            continue;
        }

        if(zz%2==1){

            cout << ":-( Try again.\n";
            continue;
        }

        for(int j=1;j<=zz;j++){

            if(z[j]<0) ne++;
            else po++;
        }
        if(po!=ne){

            cout << ":-( Try again.\n";
            continue;
        }

        int a0=0;
        for(int j=1;j<=zz;j++){

            if(z[j]==0){

                a0=1;
                break;
            }
        }
        if(a0==1){

            cout << ":-( Try again.\n";
            continue;
        }

        while(i<zz){

            if(z[i]==-z[i+1]){

                yy++;
                y[yy]=i;
                k[i]=1;
                k[i+1]=1;

            }

            i++;

        }

        while(xx<=yy){


            for(int j=0;;j++){

                if(y[xx]-j<1) break;

                if(z[y[xx]+j+1] == -z[y[xx]-j]){

                    if(z[y[xx]+j+1] > m[y[xx]]){

                        for(int f=0;f<=j;f++){

                            m[y[xx]+1+f]=z[y[xx]+1+j];
                            m[y[xx]-f]=z[y[xx]+1+j];
                            q[y[xx]+1+f]=qq;
                            q[y[xx]-f]=qq;
                        }

                        qq++;
                    }
                    else ans=1;

                    k[y[xx]+j+1]=1;
                    k[y[xx]-j]=1;

                }
                else{

                    break;

                }

            }

            xx++;

        }

        for(int j=y[1]+2;j<=zz;j++){

            if(k[j]==0 && z[j]>0){

                for(int u=j-1;u>=1;u--){

                    if(k[u]==0 && z[u] == -z[j]){

                        int total=0,g=0;

                        for(int r=j-1;r>u;r--){

                            if(q[r]!=g){

                                g=q[r];
                                total+=m[r];

                            }

                        }

                        if(z[j] > total){

                            k[j]=1;
                            k[u]=1;
                            for(int f=u;f<=j;f++){

                                m[f]=z[j];
                                q[f]=qq;

                            }
                            qq++;
                            break;

                        }
                        else{

                            ans=1;
                            break;

                        }
                    }
                    else if(k[u]==0 && z[u]<0){

                        ans=1;
                        break;

                    }

                }
            }
            else continue;
        }
/*
        int ma=-1000000000;

        for(int j=1;j<=zz/2;j++){

            if(z[j] == -z[zz+1-j]){

                if(z[j] > ma) ma=z[j];
                    else ans=1;

                k[j]=1;
                k[zz+1-j]=1;

            }
            else{

                int total=0,g=0;

                for(int u=j+1;u<=zz+1-j;u++){

                    if(q[u]!=g){

                        g=q[u];
                        total+=m[u];

                    }

                }

                if(total >= z[zz+2-j]) ans=1;
                break;
            }
        }
*/
        for(int j=1;j<=zz;j++){

            if(k[j]==0){

                ans=1;
                break;

            }

        }

        if(ans==1){

            cout << ":-( Try again.\n";

        }
        else{

            cout << ":-) Matrioshka!\n";

        }

    }

    return 0;

}
