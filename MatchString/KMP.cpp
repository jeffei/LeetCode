
vector<int> getNext(const string& pattern){
	int len=pattern.size();
	vector<int> next(len,-1);
	for(int i=1;i<len;i++){
		int j=next[i-1];
		while((pattern[i]!=pattern[j+1]) && j>=0) j=next[j];
		if(pattern[i]==pattern[j+1]) next[i]=j+1;
	}
	return next;
}
int findKMP(const string& src,const string& pattern){
	int m=src.size();
	int n=pattern.size();
	vector<int> next=getNext(pattern);
	int mIdx=0;
	int nIdx=0;
	while(mIdx<m && nIdx<n){
		if(src[mIdx]==pattern[nIdx]){
			mIdx++;nIdx++;
		}else{
			if(nIdx==0) mIdx++;
			else nIdx=next[nIdx-1]+1;
		}
	}
	if(nIdx<n) return -1;
	else return mIdx-n;
}