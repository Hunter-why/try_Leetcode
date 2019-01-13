/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// Method 1:  recursively, judge if subtree with rootnode "root" are complete or not.
//            if yes, return node count via regular count = (1 << height) -1.
//            if not, judge it's left and right subtree, respectively.
class Solution {
public:
    int countNodes(TreeNode* root) {
        if (root == nullptr) 
            return 0;
        int hl = 0, hr = 0;
        TreeNode *nl = root, *nr = root;
        while (nl) {
            nl = nl->left;
            ++hl;
        }
        while (nr) {
            nr = nr->right;
            ++hr;
        }
        if (hl == hr)
            return (1 << hl)-1;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};

// Method 2: Iteratively, reach the rightmost node of current node's left subtree through "level", judge if it is nullptr
//           if not, this left subtree is complete, let current node be right subtree's root, minus level by 1 to reach the lowest level node
//           if yes, left subtree is not full, let current node be left subtree's root, minus level by 1 
//           by the way, if left subtree is full, the last right-most node won't add to total number, because level has been minused by 1, so judge it when loop end
class Solution {
public:
    int countNodes(TreeNode* root) {
        if (root == nullptr)
            return 0;
        int height = 0, level = 0, last = 0;
        TreeNode *tmp = root;
        while (tmp) {
            tmp = tmp->left;
            ++height;
        }
        
        tmp = root;
        level = height - 2;
        while (level >= 0) {
            TreeNode *left = tmp->left;
            for (int i=0; i<level; ++i)
                left = left->right;
            if (left != nullptr) {
                last += (1 << level);
                tmp = tmp->right;
            }
            else 
                tmp = tmp->left;
            --level;
        }
        if (tmp) ++last;
        return (1 << (height-1)) -1 + last;
    }
};