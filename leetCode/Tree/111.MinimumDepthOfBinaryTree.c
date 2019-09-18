 struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

int minDepth(struct TreeNode* root){
	if(!root) return 0;
	int left=0, right=0;
	left = minDepth(root->left) + 1;
	right = minDepth(root->right) + 1;
	if(!root->left) return right;
	if(!root->right) return left; 
	return left < right ? left : right;
}