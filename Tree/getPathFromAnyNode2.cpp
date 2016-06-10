/*
	不限开始，不限结尾，
	沿路径组合
	
	method2：没有父亲节点
*/
//输出满足条件之路径
vector<int> print2(vector<int>& path,int startPos){
	vector<int> ret;
	for(int i=startPos;i<path.size();i++)
		ret.push_back(path[i]);
	return ret;
}


void getPath2(TreeNode* root,int sum,int level,
				vector<int>& path,vector<vector<int> >& res){
	if(!root) return;
	int tmp=0;
	path.push_back(root->val);
	for(int i=level;i>=0;i--){
		tmp+=path[i];
		if(tmp==sum){
			res.push_back(print2(path,i));
		}
	}
	getPath2(root->left,sum,level+1,path,res);
	getPath2(root->right,sum,level+1,path,res);
	path.pop_back();
}
vector<vector<int> > getPath2(TreeNode* root,int sum){
	vector<vector<int> > res;
	vector<int> path;
	getPath2(root,sum,0,path,res);
	return res;
}