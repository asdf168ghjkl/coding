#include <iostream>
#include <map>
using namespace std;

struct aa{

    int key;
    aa *next;
    aa *pre;
};

class LRUCache{
public:

    int ma;
    int now;
    aa * head;
    aa * last = NULL;
    map<int , int> lru;// key value

    LRUCache(int capacity) {

        ma = capacity;
        now = 0;
        head = new aa;
    }

    int get(int key) {

        if(lru[key]){

            aa * temp = head->next;

            for(int i = 1;i <= now;i++){

                if(temp->key == key){

                    if(i != now){
                        temp->pre->next = temp->next;
                        temp->next->pre = temp->pre;
                        last->next = temp;
                        temp->pre = last;
                        temp->next = NULL;
                        last = temp;
                    }
                    return lru[key];
                }

                temp = temp->next;
            }
        }
            return -1;
    }

    void set(int key, int value) {

        if(now == 0){

            aa * temp = new aa;
            temp->key = key;
            temp->pre = head;
            now = 1;
            head->next = temp;
            lru[key] = value;
            last = temp;
        }
        else if(lru[key]){

            aa * temp = head->next;

            for(int i = 1;i <= now;i++){

                if(temp->key == key){

                    if(i != now){

                        temp->pre->next = temp->next;
                        temp->next->pre = temp->pre;
                        last->next = temp;
                        temp->pre = last;
                        temp->next = NULL;
                        last = temp;
                    }
                    else
                        lru[key] = value;
                    break;
                }

                temp = temp->next;
            }
        }
        else{

            aa * temp = new aa;
            temp->key = key;
            last->next = temp;
            temp->pre = last;
            temp->next = NULL;
            last = temp;
            lru[key] = value;
            now++;
            if(now > ma){

                lru.erase(head->next->key);
                head->next->next->pre = head;
                head->next = head->next->next;
                now--;
            }
        }
    }
};

int main(){

    LRUCache* lru = new LRUCache(2048);
    lru->set(2,1);
    lru->set(3,2);
    cout << lru->get(3);
    cout << lru->get(2);
    lru->set(4,3);
    cout << lru->get(2);
    cout << lru->get(3);
    cout << lru->get(4);
}
