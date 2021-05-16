#include <vector>
#include <iostream>

using namespace std;

class MinStack {
public:
    vector<int> vSta;

    MinStack() {

    }
    
    void push(int x) {
        vSta.push_back(x);
        return;
    }
    
    void pop() {
        vSta.erase(vSta.end() - 1);
        return;
    }
    
    int top() {
        return vSta[vSta.size() - 1];
    }
    
    int getMin() {
        
        int res = vSta[0];

        for (int i = 1; i < vSta.size(); i++)
        {
            if (vSta[i] < res)
            {
                res = vSta[i];
            }
        }

        return res;
    }
};

int main()
{
    MinStack* minStack = new MinStack();
    minStack->push(-2);
    minStack->push(0);
    minStack->push(-3);
    minStack->getMin();
    minStack->pop();
    minStack->top();
    minStack->getMin();

    return 0;
}