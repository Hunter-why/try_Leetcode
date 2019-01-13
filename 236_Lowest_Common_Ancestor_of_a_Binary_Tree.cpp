// Method : DFS, code with "//" first judge whether they are in the same side, then handle
//          Optimization: return pointer instead of bool, then we got the result. 
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr)
            return root;
        if (p == root || q == root)
            return root;
        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);
        
        if (left && right)
            return root;
        if (!left)
            return right;
        return left;
    }
//     bool traverse(TreeNode *root, TreeNode *tar) {
//         if (!root)
//             return false;
//         if (root->val == tar->val)
//             return true;
//         bool tl = root->left?traverse(root->left, tar):false;
//         bool tr = root->right?traverse(root->right, tar):false;
        
//         return tl || tr;
//     }
//     TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//         if (root == nullptr)
//             return root;
//         if (p->val== root->val || q->val == root->val)
//             return root;
//         bool pl = traverse(root->left, p);
//         // bool pr = hasNode(root->right, p);
//         bool ql = traverse(root->left, q);
//         // bool qr = hasNode(root->right, q);
//         if (pl)
//             return ql?lowestCommonAncestor(root->left, p, q):root;
//         return ql?root:lowestCommonAncestor(root->right, p, q);
//     }
};