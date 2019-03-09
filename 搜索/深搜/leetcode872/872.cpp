/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> seq1, seq2;
        get_seq(root1, seq1);
        get_seq(root2, seq2);
        return seq1 == seq2 ? true : false;
    }
    
    void get_seq(TreeNode* root, vector<int> &seq) {
        if (!root)
            return;
        if (root->left != NULL)
            get_seq(root->left, seq);
        if (root->right != NULL)
            get_seq(root->right, seq);
        if (!root->left && !root->right)
            seq.push_back(root->val);
    }
};