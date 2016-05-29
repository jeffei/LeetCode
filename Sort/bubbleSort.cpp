void bubbleSort(vector<int>& vec){
	int n=vec.size();
	for(int i=0;i<n-1;i++){
		for(int j=0;j+1<n-i;j++){
			if(vec[j]>vec[j+1])
				swap(vec[j],vec[j+1]);
		}
	}
}
