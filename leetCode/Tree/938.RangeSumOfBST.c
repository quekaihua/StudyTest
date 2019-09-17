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

int rangeSumBST(struct TreeNode* root, int L, int R){
	if(!root) return 0;
	int sum = 0;
	if(root->val >= L && root->val <= R) {
		sum += root->val;
        sum += rangeSumBST(root->right, L, R);
        sum += rangeSumBST(root->left, L, R);
	}
	if(root->val < L) { sum += rangeSumBST(root->right, L, R); }
	if(root->val > R) { sum += rangeSumBST(root->left, L, R);}

	return sum;
}