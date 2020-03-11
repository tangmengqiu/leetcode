/*
 * @lc app=leetcode id=133 lang=cpp
 *
 * [133] Clone Graph
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {}

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
class Solution {
public:
    Node* cloneGraph(Node* node) {
        //bfs
        if(!node) return nullptr;
        queue<Node*> todo;
        Node* newNode =new Node(node->val,{});
        visited[node]=newNode;
        todo.push(node);
        while(!todo.empty()){
            Node* cur=todo.front();
            todo.pop();
            for(auto nb:cur->neighbors){
                if(visited.find(nb)==visited.end()){
                    Node* n =new Node(nb->val,{});
                    visited[nb]=n;
                    todo.push(nb);
                }
                visited[cur]->neighbors.push_back(visited[nb]);
            }
        }
        return newNode;
        //dfs,faster
        // if(!node) return nullptr;
        // if(visited.find(node)==visited.end()){
        //     visited[node] =new Node(node->val,{});
        //     for(auto nb: node->neighbors){
        //         visited[node]->neighbors.push_back(cloneGraph(nb));
        //     }
        // }
        // return visited[node];
        
    }
private:
    unordered_map<Node*,Node*> visited;
};
// @lc code=end

