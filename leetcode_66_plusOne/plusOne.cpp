#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {

        for (int i = (int) digits.size() - 1; i >= 0; i--)
        {
            if (digits[i] == 9 && i != 0)
            {
                digits[i] = 0;
                continue;
            }
            else if (digits[i] == 9 && i == 0)
            {
                digits[i] = 0;
                digits.insert(digits.begin(), 1);
                return digits;
            }
            else
            {
                digits[i] = digits[i] + 1;
                break;
            }
        }

        return digits;
    }
};

int main()
{
    vector<int> vRes;
    vector<int> vDigits1 = {1, 2, 3};
    vector<int> vDigits2 = {4, 3, 2, 1};
    vector<int> vDigits3 = {9};
    Solution solution;

    vRes = solution.plusOne(vDigits1);
    for (int i = 0; i < (int) vRes.size(); i++)
    {
        cout << vRes[i] << " ";
    }
    cout << endl;

    vRes = solution.plusOne(vDigits2);
    for (int i = 0; i < (int) vRes.size(); i++)
    {
        cout << vRes[i] << " ";
    }
    cout << endl;

    vRes = solution.plusOne(vDigits3);
    for (int i = 0; i < (int) vRes.size(); i++)
    {
        cout << vRes[i] << " ";
    }
    cout << endl;

    return 0;
}