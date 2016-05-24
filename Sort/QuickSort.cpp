/*
	快速排序
	两种分割方法
*/
int partition(vector<int>& res,int left,int right){
	int low=left;
	int pivot=res[left];
	for(int i=left+1;i<=right;i++){
		if(res[i]<=pivot){
			low++;
			swap(res[low],res[i]);
		}
	}
	swap(res[low],res[left]);
	return low;
}
int partition1(vector<int>& res,int left,int right){
	int pivot=res[left];
	while(left<right){
		while(res[right]>pivot &&left<right)right--;
		if(left<right)res[left++]=res[right];
		while(res[left]<=pivot &&left<right)left++;
		if(left<right)res[right--]=res[left];
	}
	res[left]=pivot;
	return left;
}
void Qsort(vector<int>& res,int left,int right){
	if(left>=right) return;
	int pos = partition1(res,left,right);
	Qsort(res,left,pos-1);
	Qsort(res,pos+1,right);
}
void QSort(vector<int>& res){
	Qsort(res,0,res.size()-1);
}