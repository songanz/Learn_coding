#include "header.h"
using namespace std;

class ZigzagIterator {
public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        b[0] = v1.begin();
        b[1] = v2.begin();
        e[0] = v1.end();
        e[1] = v2.end();
        p = 0;
    }

    int next() {
        int ret = 0;
        if (b[0] == e[0]) ret = *b[1]++;
        else if (b[1] == e[1]) ret = *b[0]++;
        else {
            ret = *b[p]++;            
            p = (1+p) % 2;
        }
        return ret;
    }

    bool hasNext() {
        return !(b[0] == e[0] && b[1] == e[1]);
    }

private:
    int p;
    vector<int> :: iterator b[2], e[2];
};

int main () {
    vector<int> v1 = {1,2,3,4};
    vector<int> v2 = {5,6,7,8};
    ZigzagIterator s(v1, v2);
    cout << s.next() << s.next() << s.next() << s.next() << endl;
}