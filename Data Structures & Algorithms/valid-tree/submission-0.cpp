class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adjList = vector<vector<int>>(n);
        vector<bool> visited = vector<bool>(n, false);
        int nodeCount = 0;
        queue<int> q;

        for (vector<int> edge: edges) {
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }

        q.push(0);

        while(!q.empty()) {
            nodeCount++;
            int curNode = q.front();
            q.pop();
            visited[curNode] = true;
            for (int adj: adjList[curNode]) {
                if (!visited[adj]) {
                    q.push(adj);
                }
                
            }
        }


        return nodeCount == n && edges.size() == n-1;
    }


};
