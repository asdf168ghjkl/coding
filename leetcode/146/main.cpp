#include <iostream>
#include <unordered_map>
#include <list>
#include <utility>
using namespace std;

class LRUCache{
public:

    int ma;
    int now;
    list<int> lru;
    unordered_map<int , pair<int, list<int>::iterator> > lru1;// key value position
    unordered_map<int , pair<int, list<int>::iterator> > :: iterator i;
    LRUCache(int capacity){

        ma = capacity;
        now = 0;
    }

    int get(int key){

        i = lru1.find(key);

        if(i != lru1.end()){

            lru.splice(lru.end(),lru,i->second.second);
            i->second.second = --(lru.end());

            return i->second.first;
        }
            return -1;
    }

    void set(int key, int value) {

        i = lru1.find(key);

        if(i != lru1.end()){

            lru.splice(lru.end(),lru,i->second.second);
            i->second.second = --(lru.end());

            i->second.first = value;

        }
        else{

            lru.push_back(key);
            lru1[key].first = value;
            lru1[key].second = --(lru.end());
            now++;

            if(now > ma){

                lru1.erase(lru.front());
                lru.pop_front();
                now--;
            }
        }
    }
};

int main(){

    LRUCache* lru = new LRUCache(2);

    lru->set(2,1);
    lru->set(1,1);
    cout << lru->get(2);
    lru->set(4,1);
    cout << lru->get(1);
    cout << lru->get(2);


}
