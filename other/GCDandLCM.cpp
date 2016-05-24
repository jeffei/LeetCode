vector<int> GCDandLCM(int m,int n){
	int s=m*n;
	while(n!=0){
		int r=m%n;
		m=n;
		n=r;
	}
	vector<int> res;
	res.push_back(m);
	res.push_back(s/m);
	return res;
}