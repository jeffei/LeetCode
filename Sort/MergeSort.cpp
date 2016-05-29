vector<int> MergeSort(vector<int> vec1,vector<int> vec2){
	vector<int> ret(vec1.size()+vec2.size());
	int cur=-1;
	for(int i=0,j=0;i<vec1.size() || j<vec2.size() ;){
		int val1=i<vec1.size() ? vec1[i]:INT_MAX;
		int val2=j<vec2.size() ? vec2[j]:INT_MAX;
		if(val1<val2) {ret[++cur]=val1;++i;}
		else{ret[++cur]=val2;++j;}
	}
	return ret;
}
vector<int> GuiBin(vector<int>& vec,int left,int right){
	if(left>=right){
		return vector<int>(1,vec[left]);
	}
	int mid=left+(right-left)/2;
	vector<int> vec1=GuiBin(vec,left,mid);
	vector<int> vec2=GuiBin(vec,mid+1,right);
	vector<int> ret=MergeSort(vec1,vec2);
	return ret;
}

vector<int> GuiBin(vector<int>& vec){
	vector<int> ret;
	if(!vec.empty())
		ret=GuiBin(vec,0,vec.size()-1);
	return ret;
}