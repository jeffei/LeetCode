bool isPalidrome(string s){
	int begin=0;
	int last=s.size()-1;
	while(begin<last){
		if(s[begin]!=s[last]) return false;
		else{
			++begin;
			--last;
		}
	}
	return true;
}
string longestPalidrome(string s){
	int len=s.size();
	for(int i=len;i>0;--i){
		for(int j=0;j+i<=len;j++){
			string str = s.substr(j,i);
			if(isPalidrome(str))
				return str;
		}
	}
	return "";
}