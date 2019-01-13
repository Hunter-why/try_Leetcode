// Method 1 : Use count left subtree's node nums to find out whether k-th smallest num in left subtree, right subtree or the root itself. 
class Solution {
public:
    int nodeNums(TreeNode *node) {
        if (node == nullptr)
            return 0;
        return 1 + nodeNums(node->left) + nodeNums(node->right);
    }
    int kthSmallest(TreeNode* root, int k) {
        
        int num = nodeNums(root->left);
        // cout << k << " " << num <<endl;
        if (k == num + 1)
            return root->val;
        else if (k <= num)
            return kthSmallest(root->left, k);
        else
            return kthSmallest(root->right, k-num-1);
        
    }
    
};

// Method 2: In-order way to traverse the BST, find the k-th element
class Solution {
public:
    int kthSmallest(TreeNode *root, int k) {
	    stack<TreeNode *> st;
	    TreeNode *carry = root;
	    while (true) {
	        if (carry != nullptr) {
	            st.push(carry);
	            carry = carry->left;
	        }
	        else {
	            auto node = st.top();
	            st.pop();
	            --k;
	            if (k == 0)
	                return node->val;
	            if (node->right != nullptr)
	                carry = node->right;
	        }
	    }
    }
};