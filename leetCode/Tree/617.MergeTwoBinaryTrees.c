 #include <stdlib.h>

 struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

struct TreeNode* mergeTrees(struct TreeNode* t1, struct TreeNode* t2){
	if(t1 && t2) {
		struct TreeNode* root = malloc(sizeof(struct TreeNode));
		int val;
		val = t1->val + t2->val;
		root->val = val;
		root->left = mergeTrees(t1->left, t2->left);
		root->right = mergeTrees(t1->right, t2->right);
		return root;
	} else return t1 ? t1 : t2;
}