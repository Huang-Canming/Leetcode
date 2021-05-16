#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

class Solution {
private:
    stack<int> staNum;

    void getNums(int &num1, int & num2) {
        num2 = staNum.top();
        staNum.pop();
        num1 = staNum.top();
        staNum.pop();
        return;
    }
public:
    int evalRPN(vector<string>& tokens) {
        int res = 0, tokensSize = (int)tokens.size(), num = 0, num1 = 0, num2 = 0;

        for (int i = 0; i < tokensSize; i++)
        {
            if ("+" == tokens[i]) {
                getNums(num1, num2);
                staNum.push(num1 + num2);
            } else if ("-" == tokens[i]) {
                getNums(num1, num2);
                staNum.push(num1 - num2);
            } else if ("*" == tokens[i]) {
                getNums(num1, num2);
                staNum.push(num1 * num2);
            } else if ("/" == tokens[i]) {
                getNums(num1, num2);
                staNum.push(num1 / num2);
            } else {
                num = stoi(tokens[i]);
                staNum.push(num);
            }
        }

        res = staNum.top();
        staNum.pop();
        return res;
    }  
};

int main() {
    Solution solution;
    vector<string> vecStrTokens1 = {"2","1","+","3","*"};
    vector<string> vecStrTokens2 = {"4","13","5","/","+"};
    vector<string> vecStrTokens3 = {"10","6","9","3","+","-11","*","/","*","17","+","5","+"};

    cout << solution.evalRPN(vecStrTokens1) << endl;
    cout << solution.evalRPN(vecStrTokens2) << endl;
    cout << solution.evalRPN(vecStrTokens3) << endl;

    return 0;
}