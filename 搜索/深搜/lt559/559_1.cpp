/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    int res = 0, level = 0;
    int maxDepth(Node* root) {
        return dfs(root);   
    }
    
    int dfs(Node* r) {
        if (!r)
            return 0;
        level++;
        if (level > res)
            res = level;
        for (int i = 0; i < r->children.size(); i++) {
            dfs(r->children[i]);
            level--;
        }
        return res;
    }
};