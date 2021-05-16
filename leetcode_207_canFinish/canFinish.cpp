#include <vector>
#include <queue>

using namespace std;

class Solution {
private:
    vector<vector<int>> edges;
    vector<int> indeg;
public:
    #if 0
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int course = 0;
        queue<int> queCourse;
        vector<int> res;

        /* 转化为邻接矩阵 */
        edges.resize(numCourses);
        indeg.resize(numCourses);
        for (auto vecPreReq : prerequisites) {
            edges[vecPreReq[0]].push_back(vecPreReq[1]);
            indeg[vecPreReq[0]]++;
        }

        for (int i = 0; i < numCourses; i++) {
            if (0 == indeg[i]) {
                queCourse.push(i);
                indeg[i] = -1;
            }
        }

        while (!queCourse.empty()) {
            course = queCourse.front();
            res.push_back(course);
            for (int i = )
        }
    }
    #endif

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        edges.resize(numCourses);
        indeg.resize(numCourses);
        for (const auto& info: prerequisites) {
            edges[info[1]].push_back(info[0]);
            ++indeg[info[0]];
        }

        queue<int> q;
        for (int i = 0; i < numCourses; ++i) {
            if (indeg[i] == 0) {
                q.push(i);
            }
        }

        int visited = 0;
        while (!q.empty()) {
            ++visited;
            int u = q.front();
            q.pop();
            for (int v: edges[u]) {
                --indeg[v];
                if (indeg[v] == 0) {
                    q.push(v);
                }
            }
        }

        return visited == numCourses;
    }
};

int main() {
    Solution solution;
    vector<vector<int>> prerequisites;
    prerequisites.push_back({0, 2});
    prerequisites.push_back({0, 4});
    prerequisites.push_back({0, 5});
    prerequisites.push_back({1, 0});
    prerequisites.push_back({1, 2});
    prerequisites.push_back({3, 5});
    prerequisites.push_back({5, 4});
    prerequisites.push_back({5, 6});

    solution.canFinish(7, prerequisites);

    return 0;
}