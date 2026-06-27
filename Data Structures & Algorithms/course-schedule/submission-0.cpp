class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjList = vector<vector<int>> (numCourses);
        vector<int> inEdges(numCourses, 0);
        int visited = 0;
        queue<int> q;

        for(vector<int> p: prerequisites) {
            adjList[p[0]].push_back(p[1]);
            inEdges[p[1]]++;
        }

        for(int i = 0; i < inEdges.size(); i++) {
            if (inEdges[i] == 0) {
                q.push(i);
            }
        }

        while(!q.empty()) {
            visited++;
            int curNode = q.front();
            q.pop();
            for (int adjNode: adjList[curNode]) {
                inEdges[adjNode]--;
                if(inEdges[adjNode] == 0) {
                    q.push(adjNode);
                }
            }
        }

        // cout<<visited;
        return visited == numCourses;
    }
};
