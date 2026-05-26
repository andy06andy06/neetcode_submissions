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
    Node* dfs(Node* node, unordered_map<Node*, Node*> &hashmap){
        if(node==nullptr) return nullptr;
        if(hashmap.count(node)) return hashmap[node];
        
        Node* newnode = new Node(node->val);
        hashmap[node] = newnode;
        for(Node* n : node->neighbors){
            newnode->neighbors.push_back(dfs(n, hashmap));
        }
        return newnode;
    }

    Node* cloneGraph(Node* node) {
        unordered_map<Node*, Node*> hashmap;
        return dfs(node, hashmap);
    }
};
