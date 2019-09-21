 #include <stdlib.h>
 #include <stdbool.h>

 struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

void inOrder(struct TreeNode* root, int* sum){
	if(!root) return;
	inOrder(root->right, sum);
	root->val += *sum;
	*sum = root->val;
	inOrder(root->left, sum);
}

struct TreeNode* bstToGst(struct TreeNode* root){
	if(!root) return NULL;
	int sum = 0;
	inOrder(root, &sum);
	return root;
}