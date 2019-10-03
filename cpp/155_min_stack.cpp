#include "header.h"
using namespace std;

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {        
    }
    
    void push(int x) {        
        data.push(x);
        
        if (minS.empty()) {
            minS.push(x);
            return;
        }
        
        int top = minS.top();
        if (minS.top() < x) minS.push(top);
        else minS.push(x);
    }
    
    void pop() {        
        if (data.empty()) return;
        data.pop();
        minS.pop();
    }
    
    int top() {        
        return data.top();
    }
    
    int getMin() {        
        return minS.top();
    }
private:
    stack<int> data;
    stack<int> minS;
};

int main() {
    MinStack m;
    m.push(-2);
    m.push(0);
    m.push(-3);
    cout << m.getMin() << '\t';
    m.pop();
    cout << m.top() << '\t';
    cout << m.getMin() << '\n';
}