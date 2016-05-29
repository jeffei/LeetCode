void maxHeapFix(vector<int>& A,int startPos,int endPos){
	int left=2*startPos+1;
	int right=2*startPos+2;
	int largest=startPos;
	if(left<=endPos && A[left]>A[largest])  largest=left;
	if(right<=endPos && A[right]>A[largest]) largest=right;
	if(largest!=startPos){
		swap(A[largest],A[startPos]);
		maxHeapFix(A,largest,endPos);
	}
}
void bulidMaxHeap(vector<int>& vec){
	int len=vec.size();
	for(int i=(len-1)/2;i>=0;i--){
		maxHeapFix(vec,i,len-1);
	}
}
void heapSort(vector<int>& vec){
	bulidMaxHeap(vec);
	int len=vec.size()-1;
	for(int i=len;i>=1;i--){
		swap(vec[0],vec[len]);
		len--;
		maxHeapFix(vec,0,len);
	}
}