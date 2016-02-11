#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int box,student;
    int boxes[10003]={0};
    int sec=1;
    int *s1 = new int [10003];
    int *s2 = new int [10003];

    for(int i=1;i<=10003;i++){

        s1[i]=0;
        s2[i]=0;
    }

    cin >> box >> student;

    for(int i=1;i<=box;i++)
        cin >> boxes[i];

    s1[1]=student;

    int top=1,dow=1;

    while(boxes[box]!=0){

        sec++;

        for(int i=dow;i<=top;i++){

            if(boxes[i]==0){

                s2[i+1]+=s1[i];
                s1[i]=0;
                if(i==dow) dow++;
                if(dow > top) top++;
            }
            else if(s1[i]>boxes[i]){

                s2[i+1] += (s1[i]-boxes[i]);
                s2[i] += boxes[i];
                boxes[i]=0;
                s1[i]=0;
                if(i==top){

                    top++;
                    break;
                }
            }
            else{

                boxes[i]-=s1[i];
                s2[i]+=s1[i];
                s1[i]=0;
            }
        }

        swap(s1,s2);
    }

    delete [] s1;
    delete [] s2;

    cout << sec << endl;
    return 0;
}
