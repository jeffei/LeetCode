void getResut(long long path,int cur,vector<bool>& isUsed,vector<long long>& ret){
	if(cur>1&&path%cur!=0) return;
	if(cur==10){
		ret.push_back(path);
		return;
	}
	for(int i=0;i<=9;i++){
		if(isUsed[i]) continue;
		if(path*10+i==0) continue;
		isUsed[i]=true;
		getResut(path*10+i,cur+1,isUsed,ret);
		isUsed[i]=false;
	}
}
vector<long long> getResut(){
	vector<long long> ret;
	vector<bool> isUsed(10,false);
	getResut(0,0,isUsed,ret);
	return ret;
}