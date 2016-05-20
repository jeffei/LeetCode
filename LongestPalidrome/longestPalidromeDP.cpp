string longestPalidromeDP(const string& src){
	const int m=src.size();
	vector<vector<bool> >  L(m,vector<bool>(m,false));//L[i][j]:表示i到j的Palidrome长度
	int maxLen=0;
	int startPos=-1;
	for(int i=0;i<m;i++) {	L[i][i]=true;maxLen=1;startPos=i;}
	for(int i=0;i+1<m;i++){ if(src[i]==src[i+1]){L[i][i+1]=true;maxLen=2;startPos=i;}}	
	for(int len=3;len<=m;len++){
		for(int i=0;i+len<=m;i++){
			int j=i+len-1;
			if(src[i]==src[j] && L[i+1][j-1]){
				L[i][j]=true;
				maxLen=len;
				startPos=i;
			}
		}
	}
	return src.substr(startPos,maxLen);
} //O(N*N)