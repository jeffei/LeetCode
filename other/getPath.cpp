/*
	不限开始，不限结尾，
	沿路径组合
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct TreeNode{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode* parent;
	TreeNode(int val):val(val),left(nullptr),right(nullptr),parent(nullptr){}
};
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
vector<int> print2(vector<int>& path,int startPos){
	vector<int> ret;
	for(int i=startPos;i<path.size();i++)
		ret.push_back(path[i]);
	return ret;
}
void getPath2(TreeNode* root,int sum,int level,vector<int>path,vector<vector<int> >& res){
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
}
vector<vector<int> > getPath2(TreeNode* root,int sum){
	vector<vector<int> > res;
	vector<int> path;
	getPath2(root,sum,0,path,res);
	return res;
}
int main(){
	TreeNode a(2),b(3),c(4),d(2),e(2),f(1),g(-1);
	a.left=&b;a.right=&c;c.parent=&a;b.parent=&a;
	b.left=&d;d.parent=&b;
	c.left=&f;c.right=&g;f.parent=&c;g.parent=&c;
	
	vector<vector<int> > ret2=getPath(&a,5);
	vector<vector<int> > ret3=getPath2(&a,5);
	return 0;
}