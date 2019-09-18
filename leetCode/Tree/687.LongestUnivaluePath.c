 struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

int travel(struct TreeNode* root, int val, int *max){
	if(!root) return 0;
	int path = 0;
	if(val == root->val) path++;
	// else {
	// 	if(*max < path) *max = path;
	// }
	path += travel(root->left, val, max);
	path += travel(root->right, val, max);
	return path;
}

int longestUnivaluePath(struct TreeNode* root){
	if(!root) return 0;
	int length = 0, max = 0, val=root->val;
	travel(root, val, &max);
	return max;
}