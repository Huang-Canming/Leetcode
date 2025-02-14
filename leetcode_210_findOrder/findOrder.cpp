#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> res;
        if (1 == numCourses) {
            res.push_back(0);
            return res;
        }

        vector<vector<int>> graph(numCourses);  // 邻接矩阵
        vector<int> inDegree(numCourses);       // 入度表
        queue<int> goFinish;                    // 可学习课程
        int prevCourse = 0;
        int nextCourse = 0;

        // 构建邻接矩阵和入度表
        for (int i  = 0; i < prerequisites.size(); i++) {
            prevCourse = prerequisites[i][1];
            nextCourse = prerequisites[i][0];
            graph[prevCourse].push_back(nextCourse);   // 后继课程
            inDegree[nextCourse]++;
        }

        // 找出入度为 0 的课程（没有前置课程）先进行学习
        for (int i = 0; i < inDegree.size(); i++) {
            if (0 == inDegree[i]) {
                goFinish.push(i);
            }
        }

        while (0 != goFinish.size()) {
            prevCourse = goFinish.front();
            goFinish.pop();
            res.push_back(prevCourse);
            // 完成一门课程后，减少后继课程的入度
            for (int i = 0; i < graph[prevCourse].size(); i++) {
                nextCourse = graph[prevCourse][i];
                inDegree[nextCourse]--;
                // 对于新的入度为 0 的课程，加入队列准备学习
                if (0 == inDegree[nextCourse]) {
                    goFinish.push(nextCourse);
                }
            }
        }

        if (res.size() < numCourses) {
            res.clear();
        }

        return res;
    }
};

int main(){
    Solution solu;
    int numCourses = 1;
    vector<vector<int>> prerequisites;

    vector<int> res = solu.findOrder(numCourses, prerequisites);
    for (int course : res) {
        cout << course << " ";
    }
    cout << endl;

    return 0;
}