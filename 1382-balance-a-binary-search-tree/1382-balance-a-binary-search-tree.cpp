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
    vector<TreeNode*> arr;
    TreeNode* balanceBST(TreeNode* root) {
        inorder(root);
        return sorted(0, arr.size() - 1);
    }
      void inorder(TreeNode* root) {
        if (root == NULL) return;
        inorder(root->left);
        arr.push_back(root);
        inorder(root->right);
    }
     TreeNode* sorted(int start, int end) {
        if (start > end) return NULL;
        int mid = (start + end) / 2;
        TreeNode* root = arr[mid];
        root->left = sorted(start, mid - 1);
        root->right = sorted(mid + 1, end);
        return root;
    }
    
};

