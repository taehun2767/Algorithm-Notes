/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    int k;
    int i;
    int ret;
    bool traverse(TreeNode* node){
        if(node == nullptr) return false;
        bool b = traverse(node -> left);
        if(b) return b;
        if(++i == k){
            ret = node -> val;
            return true;
        }
        return traverse(node -> right);
    }
    int kthSmallest(TreeNode* root, int k) {
        this -> k = k;
        traverse(root);
        return ret;
    }
};
