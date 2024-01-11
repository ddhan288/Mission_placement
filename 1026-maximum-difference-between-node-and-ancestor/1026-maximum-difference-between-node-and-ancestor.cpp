class Solution {
private:
    int maxDiff;

    void maxDiffUtil(TreeNode* root, TreeNode* child) {
        if (root == nullptr || child == nullptr) return;

        maxDiff = std::max(maxDiff, std::abs(root->val - child->val));

        maxDiffUtil(root, child->left);
        maxDiffUtil(root, child->right);
    }

    void findMaxDiff(TreeNode* root) {
        if (root == nullptr) return;

        maxDiffUtil(root, root->left);
        maxDiffUtil(root, root->right);

        findMaxDiff(root->left);
        findMaxDiff(root->right);
    }

public:
    int maxAncestorDiff(TreeNode* root) {
        maxDiff = -1;
        findMaxDiff(root);
        return maxDiff;
    }
};