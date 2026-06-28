class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        unordered_map<char, vector<char>> adjList;
        unordered_map<char, int> inNodes;
        string result = "";
        int n = words.size();
        queue<char> q;

        for (const auto& w : words) {
            for (char c : w) {
                if (adjList.find(c) == adjList.end()) {
                    adjList[c] = {};
                    inNodes[c] = 0;
                }
            }
        }

        for (int i = 0; i < n - 1; ++i) {
            string w1 = words[i], w2 = words[i+1];
            int minLen = min(w1.size(), w2.size());
            if (w1.size() > w2.size() && w1.substr(0, minLen) == w2.substr(0, minLen)) return "";
            for (int j = 0; j < minLen; j++) {
                if (w1[j] != w2[j]) {
                    adjList[w1[j]].push_back(w2[j]);
                    inNodes[w2[j]]++;
                    break;
                }
            }
        }

        for (const auto& [key, value] : adjList) {
           if (inNodes[key] == 0) {
                q.push(key);
           }
        }

        while(!q.empty()) {
            char node = q.front();
            q.pop();
            result += node;

            for(char c: adjList[node]) {
                inNodes[c]--;
                if (inNodes[c] == 0) {
                    q.push(c);
                }
            }
        }
        
        return result.length() == adjList.size() ? result : "";
    }
};