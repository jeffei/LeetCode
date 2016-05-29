void inSertSort(vector<int>& vec){
	for(int i=1;i<vec.size();i++){
		int cur=vec[i];
		int j=i-1;
		while(j>=0 && vec[j]>cur){
			vec[j+1]=vec[j];
			j--;
		}
		vec[j+1]=cur;
	}
}