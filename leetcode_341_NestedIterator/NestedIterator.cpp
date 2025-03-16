#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// This is the interface that allows for creating nested lists.
// You should not implement it, or speculate about its implementation
class NestedInteger {
private:
    vector<NestedInteger> valVec;
    int val;
    bool isInt;
public:
    NestedInteger (int val) : val(val), isInt(true) { };
    NestedInteger (vector<NestedInteger> &valVec) : valVec(valVec), isInt(false) { };

    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() {
        return isInt;
    }

    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() {
        return val;
    }

    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    vector<NestedInteger> &getList() {
        return valVec;
    }
};

class NestedIterator {
private:
    stack<pair<vector<NestedInteger>::iterator, vector<NestedInteger>::iterator>> stk;
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        #if 0
        stk.push(pair<vector<NestedInteger>::iterator, vector<NestedInteger>::iterator>
                (nestedList.begin(), nestedList.end()));
        #else
        stk.emplace(nestedList.begin(), nestedList.end());
        #endif
        return;
    }
    
    int next() {
        // hasNext() 接口已经保证了直接取到的就是下一个整数
        int res = stk.top().first->getInteger();
        stk.top().first++;
        return res;
    }

    bool hasNext() {
        while (!stk.empty()) {
            auto curPos = stk.top();
            if (curPos.first == curPos.second) {
                stk.pop();
            } else if (curPos.first->isInteger()) {
                return true;
            } else {
                // 嵌套 vector 的场景，先把上层的下一个 iter 压栈，再把 sub vec 的 iter 压栈
                vector<NestedInteger> &subVec = curPos.first->getList();
                stk.top().first++;
                stk.emplace(subVec.begin(), subVec.end());
            }
        }
        return false;
    }
};

int main () {
    NestedInteger integer0_1(10);
    NestedInteger integer0_2(11);
    vector<NestedInteger> vecVal0 = {integer0_1, integer0_2};
    NestedInteger integer0(vecVal0);
    NestedInteger integer1(12);
    NestedInteger integer2_0(13);
    NestedInteger integer2_1(14);
    vector<NestedInteger> vecVal2 = {integer2_0, integer2_1};
    NestedInteger integer2(vecVal2);

    vector<NestedInteger> nestedList = {vecVal0, integer1, vecVal2};
    NestedIterator i(nestedList);
    while (i.hasNext()) cout << i.next() << endl;

    return 0;
}