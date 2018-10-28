void getPermutation(vector<int>& src,int cur,vector<vector<int> >& res){
	if(cur==src.size()) {res.push_back(src);return;}
	for(int i=cur;i<src.size();i++){
		swap(src[cur],src[i]);
		getPermutation(src,cur+1,res);
		swap(src[cur],src[i]);
	}
}
vector<vector<int> > getPermutation(vector<int>& src){
	vector<vector<int> > res;
	getPermutation(src,0,res);
	return res;
}