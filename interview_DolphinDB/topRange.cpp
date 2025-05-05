#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// 因为每个元素最多入栈和出栈一次，所以时间复杂度为 O(n)，其中 n 是数组 v 的长度。
vector<int> topRange(vector<double>& v) {
    vector<int> result(v.size());
    stack<double> stack;
    
    for (int i = 0; i < v.size(); ++i) {
        while (!stack.empty() && v[stack.top()] < v[i]) {
            // 小于当前元素的栈顶元素出栈
            stack.pop();
        }
        if (stack.empty()) {
            // 如果栈为空，则当前元素为最大值，范围从 1 开始
            result[i] = i + 1;
        } else {
            // 当前元素为栈顶元素与当前元素之间的距离
            result[i] = i - stack.top();
        }
        stack.push(i);
    }
    
    return result;
}

int main () {
    vector<double> v = {13.5, 13.6, 13.4, 13.3, 13.5, 13.9, 13.1, 20.1, 20.2, 20.3};
    vector<int> res = topRange(v);
    cout << "The top range is: ";
    for (double num : res) {
        cout << " " << num;
    }
    cout << endl;
    return 0;
}