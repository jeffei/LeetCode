/*
	找出超过一半的元素

*/
int findMostEle(vector<int>& vec){
	int n=vec.size();
	int candidate = vec[0];
	int time =1;
	for(int i=1;i<n;i++){
		if(time==0){
			candidate=vec[i];
			time=1;
		}else{
			if(vec[i]==candidate){time++;}
			else{
				candidate=vec[i];
				time--;
			}
		}
	}
	return candidate;
}