
struct TreeNode{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int val):val(val),left(nullptr),right(nullptr){}
};
bool isMatch(TreeNode* root1,TreeNode* root2){
	if(!root1 && !root2) return true;
	if(!root1 || !root2) return false;
	if(root1->val != root2->val) return false;
	return isMatch(root1->left,root2->left) && isMatch(root1->right,root2->right);
}
bool isSubStree(TreeNode* root1,TreeNode* root2){
	if(!root1) return false;
	if(!root2) return true;
	if(root1->val==root2->val){
		if(isMatch(root1,root2))
			return true;
	}
	return isSubStree(root1->left,root2) || isSubStree(root1->right,root2);
}