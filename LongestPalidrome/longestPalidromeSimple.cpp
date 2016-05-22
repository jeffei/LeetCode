string expand(string s,int begin,int last){
	int len=s.size();
	while(begin>=0 && last<len && s[begin]==s[last]){
		begin--;
		last++;
	}
	return s.substr(begin+1,last-1-(begin+1)+1);
}
string longestPalidromeSimple(string s){
	int len = s.size();
	string maxPaString=s.substr(0,1);
	for(int i=1;i<len-1;i++){
		string tmpString =expand(s,i,i);
		if(tmpString.size()>maxPaString.size())
			maxPaString=tmpString;
		tmpString = expand(s,i,i+1);
		if(tmpString.size()>maxPaString.size())
			maxPaString=tmpString;
	}
	return maxPaString;
} //O(N*N) space O(1)