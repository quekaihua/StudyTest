 #include <stdlib.h>
 #include <stdbool.h>

 struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

bool isUnivalTree(struct TreeNode* root){
	if(!root) return true;
    if(!root->left && !root->right) return true;
	
	if(root->left) {
		if(root->left->val != root->val) return false;
	}
	if(root->right) {
		if(root->right->val != root->val) return false;
	}
    
	return isUnivalTree(root->left) && isUnivalTree(root->right);
	
}
