#include <iostream>
#include <map>
#include <algorithm>
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
    aa * head = NULL;
    aa * last = NULL;
    map<int , int> lru;// key value

    LRUCache(int capacity) {

        ma = capacity;
        now = 0;
    }

    int get(int key) {

        if(lru[key]){

            aa * temp = head->next;

            for(int i = 0;i < now;i++){

                if(temp->key == key){

                    temp->pre->next = temp->next;
                    if(temp->next) temp->next->pre = temp->pre;

                    last->next = temp;
                    temp->pre = last;
                    temp->next = NULL;
                    last = temp;
                    return lru[key];
                }

                temp = temp->next;
            }
        }
        else{

            return -1;
        }

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

            for(int i = 0;i < now;i++){

                if(temp->key == key){

                    temp->pre->next = temp->next;
                    if(temp->next) temp->next->pre = temp->pre;

                    last->next = temp;
                    temp->pre = last;
                    temp->next = NULL;
                    last = temp;
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

    LRUCache* lru = new LRUCache(2);
    lru->set(2,1);
    lru->set(1,1);
    lru->get(2);
    lru->set(4,1);
    lru->get(1);
    lru->get(2);


}
