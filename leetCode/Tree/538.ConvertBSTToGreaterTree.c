/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
 };
 
void inorder(struct TreeNode* root, int *sum)
{
	if(!root) return;
	inorder(root->right, sum);
	root->val += *sum;
	*sum = root->val;
	inorder(root->left, sum);
}

struct TreeNode* convertBST(struct TreeNode* root){
	int sum=0;
	inorder(root, &sum);
	return root;
}