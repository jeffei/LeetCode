/*
	不限开始，不限结尾，
	沿路径组合
	method1：有父亲节点，从每一个节点向上遍历，同时记录遍历步数，若满足条件则进行输出；不满足则从当前节点的两个孩子节点递归遍历


*/
vector<int> print(TreeNode* root,int len){
	vector<int> res;
	for(int i=0;i<len;i++){
		res.push_back(root->val);
		root=root->parent;
	}
	reverse(res.begin(),res.end());
	return res;
}
void getPath(TreeNode* root,int sum,vector<vector<int> >& res){
	if(!root) return;
	int tmp=0;
	TreeNode* node=root;
	for(int i=1;node;i++){
		tmp+=node->val;
		if(tmp==sum) res.push_back(print(root,i));
		node=node->parent;
	}
	getPath(root->left,sum,res);
	getPath(root->right,sum,res);
}
vector<vector<int> > getPath(TreeNode* root,int sum){
	vector<vector<int> > res;
	getPath(root,sum,res);
	return res;
}