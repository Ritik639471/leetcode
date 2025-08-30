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
    Node* cloneGraph(Node* node) {
        if (node == NULL) return node;
        map<Node*,Node*>mp;
        Node* temp;
        queue<Node*>q;
        q.push(node);
        unordered_set<Node*>visited;
        while(q.size()>0){
            temp=new Node(q.front()->val);
            mp[q.front()]=temp;
            temp=q.front();
            visited.insert(temp);
            q.pop();
            for( auto c: temp->neighbors){
              if(visited.count(c)>0) continue;
              q.push(c);
            }
        }
        q.push(node);
        visited.clear();
        while(q.size()>0){
            temp=mp[q.front()];
            Node* ab=q.front();
            q.pop();
            if(visited.count(ab)) continue;
            visited.insert(ab);
            
            for( auto c: ab->neighbors){
              temp->neighbors.push_back(mp[c]);
              if(visited.count(c)>0) continue;
              q.push(c);
            }
        }
        return mp[node];
    }
};