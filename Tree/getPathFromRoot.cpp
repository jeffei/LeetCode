/*
	输入：root ，target
	输出：路径
	路径必须从跟开始

*/
void getPath(TreeNode* root,int gap,vector<int>& path, vector<vector<int> >& ret){
	if(!root) return;
	if(gap==root->val){
		path.push_back(root->val);
		ret.push_back(path);
		path.pop_back();
		return;
	}
	path.push_back(root->val);
	getPath(root->left,gap-root->val,path,ret);
	getPath(root->right,gap-root->val,path,ret);
	path.pop_back();
}
vector<vector<int> > getPath(TreeNode* root, int target){
	vector<vector<int> > ret; 
	vector<int> path;
	getPath(root,target,path,ret);
	return ret;
}