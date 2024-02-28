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
    Node* dfs(Node* node, unordered_map<Node*, Node*> &mp){
        Node* temp = new Node(node->val);
        vector<Node*> newNeighbors;
        mp[node] = temp;
        for(auto n: node->neighbors){
            if(mp.find(n) != mp.end()){
                newNeighbors.push_back(mp[n]);
            }
            else{
                newNeighbors.push_back(dfs(n, mp));
            }    
        } 
        temp->neighbors = newNeighbors;
        return temp;
    }
    Node* cloneGraph(Node* node) {
        unordered_map<Node*, Node*> mp;
        if(node == NULL)
            return NULL;
        if(node->neighbors.size() == 0)
            return new Node(node->val);
        return dfs(node, mp);
    }
};