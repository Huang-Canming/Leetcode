#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> indegree(numCourses, 0);
        queue<int> goFinish;
        int finishNum = 0;
        int prevCourse = 0;
        int nextCourse = 0;

        // 构建邻接矩阵和入度表
        for (int i = 0; i < prerequisites.size(); i++) {
            // 边的方向是从 prerequisites[i][1] 指向 prerequisites[i][0]
            prevCourse = prerequisites[i][1];
            nextCourse = prerequisites[i][0];
            graph[prevCourse].push_back(nextCourse);
            indegree[nextCourse]++;
        }

        // 所有入度为 0 的节点入队列
        for (int i = 0; i < numCourses; i++) {
            if (0 == indegree[i]) {
                goFinish.push(i);
            }
        }

        // 访问队列中的节点（出队）
        while (0 != goFinish.size()) {
            prevCourse = goFinish.front();
            goFinish.pop();
            finishNum++;
            // 若有所指向的节点，则所指节点入度减 1
            for (int i = 0; i < graph[prevCourse].size(); i++) {
                nextCourse = graph[prevCourse][i];
                indegree[nextCourse]--;
                // 若所指节点入度减 1 后变为 0，同样加入队列
                if (0 == indegree[nextCourse]) {
                    goFinish.push(nextCourse);
                }
            }
        }

        if (finishNum == numCourses) {
            return true;
        } else {
            return false;
        }
    }
};

int main() {
    Solution solution;
    vector<vector<int>> prerequisites;
    prerequisites.push_back({1, 0});
    cout << solution.canFinish(2, prerequisites) << endl;

    prerequisites.push_back({0, 1});
    cout << solution.canFinish(2, prerequisites) << endl;

    return 0;
}