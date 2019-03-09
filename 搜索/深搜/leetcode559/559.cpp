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
    int maxDepth(Node* root) {
        if (!root)
            return 0;
        if (root->children.size() == 0)
            return 1;
        int max_result = 0;
        for (int i = 0; i < root->children.size(); i++) {
            int result = maxDepth(root->children[i]);
            if (result > max_result)
                max_result = result;
        }
        return max_result + 1;  
    }
};