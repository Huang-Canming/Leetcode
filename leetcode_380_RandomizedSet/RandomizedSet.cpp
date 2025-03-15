#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class RandomizedSet {
private:
    vector<int> valVec;
    unordered_map<int, int> valHash;
public:
    RandomizedSet() {
        // 生成随机数种子
        srand((unsigned)time(NULL));
        return;
    }
    
    bool insert(int val) {
        if (valHash.end() == valHash.find(val)) {
            valVec.push_back(val);
            valHash[val] = valVec.size() - 1;
            return true;
        } else {
            return false;
        }
    }
    
    bool remove(int val) {
        if (valHash.end() == valHash.find(val)) {
            return false;
        } else {
            int rmIndex = valHash[val];
            int vecSize = valVec.size();
            // 如果删除的不是最后一个元素
            if (vecSize - 1 > rmIndex) {
                // 把 vec 最后一个元素填入被删元素的位置，并更新哈希表
                int lastIndex = vecSize - 1;
                int lastVal = valVec[lastIndex];
                valVec[rmIndex] = lastVal;
                valHash[lastVal] = rmIndex;
            }
            valHash.erase(val);
            valVec.pop_back();
            return true;
        }
    }
    
    int getRandom() {
        // rand() 结果对 valVec.size() 求余，得到范围是 0 ~ valVec.size() - 1 的随机数
        // 题目保证了 valVec.size() 一定大于等于 1，任意数对 1 求余的结果是 0
        int index = rand() % (valVec.size());
        return valVec[index];
    }
};

int main () {
    RandomizedSet randSet;
    cout << randSet.insert(1) << endl;
    cout << randSet.remove(2) << endl;
    cout << randSet.insert(2) << endl;
    cout << randSet.getRandom() << endl;
    cout << randSet.remove(1) << endl;
    cout << randSet.insert(2) << endl;
    cout << randSet.getRandom() << endl;
    cout << randSet.insert(3) << endl;
    cout << randSet.remove(3) << endl;
    cout << randSet.remove(0) << endl;
    cout << randSet.insert(3) << endl;
    cout << randSet.getRandom() << endl;
    cout << randSet.remove(0) << endl;
    cout << randSet.insert(3) << endl;
    cout << randSet.insert(-2) << endl;
    cout << randSet.remove(2) << endl;
    cout << randSet.insert(1) << endl;
    cout << randSet.insert(-3) << endl;
    cout << randSet.insert(-2) << endl;
    cout << randSet.remove(-2) << endl;
    cout << randSet.remove(3) << endl;
    cout << randSet.insert(-1) << endl;
    cout << randSet.remove(-3) << endl;
    cout << randSet.insert(1) << endl;
    cout << randSet.insert(-2) << endl;
    cout << randSet.insert(-2) << endl;
    cout << randSet.insert(-2) << endl;
    cout << randSet.insert(1) << endl;
    cout << randSet.getRandom() << endl;
    cout << randSet.insert(-2) << endl;
    cout << randSet.remove(0) << endl;
    cout << randSet.insert(-3) << endl;
    cout << randSet.insert(1) << endl;

    return 0;
}