int Strstr(const string& src,const string& pattern){
	const int m=src.size();
	const int n=src.size();
	for(int i=0;i<=m-n;i++){
	int j=0;
		for(;j<n;j++){
			while(j<n && src[i+j]==pattern[j]);
			if(j==n) return i;
		}
	}
	return -1;
}