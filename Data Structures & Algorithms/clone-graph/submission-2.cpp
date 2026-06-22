/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    vector<Node*> visited;
    Node* cloneGraph(Node* node) {
        visited = vector<Node*>(105, nullptr);
        return clone(node);
    }

    Node* clone(Node* node) {
        if (!node) {
            return nullptr;
        }

        Node* newNode = new Node(node->val);
        visited[node->val] = newNode;

        for (Node* neighbor: node->neighbors) {
            if (!visited[neighbor->val]) {
                clone(neighbor);
            }
            newNode->neighbors.push_back(visited[neighbor->val]);
        }

        return newNode;
    }
};
