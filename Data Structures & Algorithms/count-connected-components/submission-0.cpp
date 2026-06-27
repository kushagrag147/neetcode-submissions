class Solution {
public:
    vector<bool> visited;
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adjList = vector<vector<int>>(n);
        visited = vector<bool>(n, false);
        int connectedComponents = 0;

        for(vector<int> edge: edges) {
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }

        for (int i =0 ; i < n; i++) {
            if (!visited[i]) {
                connectedComponents++;
                dfs(i, adjList);
            }
        }

        return connectedComponents;
    }

    void dfs(int node, vector<vector<int>> adjList) {
        visited[node] = true;

        for(int adj: adjList[node]) {
            if(!visited[adj]) {
                dfs(adj, adjList);
            }
        }
    }
};
