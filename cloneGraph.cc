/* memory limit exceed
class Solution {
public:
    map<UndirectedGraphNode *, UndirectedGraphNode *> hash;
    queue<UndirectedGraphNode *>q;
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (!node) return NULL;
        q.push(node);
        UndirectedGraphNode *head = NULL;
        while ( q.size() ) {
            UndirectedGraphNode *tmp = q.front();
            if (!head)
                head = tmp;
            UndirectedGraphNode *cur = new UndirectedGraphNode(tmp->label);
            hash.insert(pair<UndirectedGraphNode *, UndirectedGraphNode *>(tmp, cur));
            for (int i = 0; i < tmp->neighbors.size(); i++) {
                if (hash.find(tmp->neighbors[i]) != hash.end())
                    q.push(tmp->neighbors[i]);
                cur->neighbors.push_back(tmp->neighbors[i]);
            }
            q.pop();
        }
        return head;
    }
};*/
//BFS
  UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (!node) return NULL;
        queue<UndirectedGraphNode *> q;
        unordered_map<UndirectedGraphNode *, UndirectedGraphNode *> hash;
        q.push(node);
        UndirectedGraphNode *root = new UndirectedGraphNode(node->label);
        hash[node] = root;
        while (q.size()) {
            UndirectedGraphNode *tmp = hash[q.front()];
            for (auto it = q.front()->neighbors.begin(); it != q.front()->neighbors.end(); it++) {
                if (hash.count(*it) > 0) {
                    tmp->neighbors.push_back(hash[*it]);
                } else {
                    UndirectedGraphNode *_tmp = new UndirectedGraphNode((*it)->label);
                    hash[*it] = _tmp;
                    tmp->neighbors.push_back(hash[*it]);
                    q.push(*it);
                }
            }
            q.pop();
        }
        return root;
    }


/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
 
class Solution {
public:
    map<UndirectedGraphNode *, UndirectedGraphNode *> hash;
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (!node) return NULL;
        hash.clear();
        return _clone(node);
    }
    
    UndirectedGraphNode * _clone(UndirectedGraphNode *node) {
        if (!node) return NULL;
        if (hash.find(node) != hash.end())
            return hash.find(node)->second;
        UndirectedGraphNode *cur = new UndirectedGraphNode(node->label);
        hash.insert( pair<UndirectedGraphNode *, UndirectedGraphNode *>(node, cur) );
        for (int i = 0; i < node->neighbors.size(); i++) {
            cur->neighbors.push_back(_clone(node->neighbors[i]));
        }
        return cur;
    }
};