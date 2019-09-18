 #include <stdlib.h>
 #include <stdbool.h>

 struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

void inorder(struct TreeNode* root, int sequence[], int *length) {
    if(!root) {
		sequence[(*length)++] = -1;
		return;
	}
	if(!root->left && !root->right) {
		sequence[(*length)++] = root->val;
		return;
	}
	inorder(root->left, sequence, length);
	inorder(root->right, sequence, length);
}

bool check(int sequence1[], int sequence2[], int length1, int length2) {
	if(length1 != length2) return false;
	for(int i=0; i<length1; i++) {
		if(sequence1[i] != sequence2[i]) return false;
	}
	return true;
}

bool isSameTree(struct TreeNode* p, struct TreeNode* q){
	int sequence1[100], sequence2[100];
	int length1 = 0, length2 = 0;
	inorder(p, sequence1, &length1);
	inorder(q, sequence2, &length2);
	return check(sequence1, sequence2, length1, length2);
}

bool isSameTree2(struct TreeNode* p, struct TreeNode* q) {
	if(p==NULL && q==NULL) return true;
	if(p==NULL || q==NULL) return false;
        
	if(p->val != q->val) return false;
	isSameTree(p->left,q->left);
	isSameTree(p->right,q->right);
}

struct TreeNode* createNode(int val)
{
	struct TreeNode* root = malloc(sizeof(struct TreeNode));
	root->left = NULL;
	root->right = NULL;
	root->val = val;
	return root;
}

int main() 
{
	struct TreeNode* root1, *root2;
	root1 = createNode(1);
	root2 = createNode(2);
	leafSimilar(root1, root2);
}