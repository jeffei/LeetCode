/*
	*桶排序，非比较性排序，突破基于比较排序的时间复杂度下界O(nlogn)
	*有些时候要比快速排序块，且是稳定排序
	*应用场景，海量数据排序，海量数据找中位数
	
	*空间换时间


*/

void BuckSort(vector<int>& vec){
	int min=vec[0];
	int max=vec[0];
	for(int i=1;i<vec.size();i++){
		if(vec[i]>max) max = vec[i];
		else if(vec[i]<min) min=vec[i];
	}
	int numOfBuck = max-min+1;
	vector<list<int> > tmp(numOfBuck);
	for(int i=0;i<vec.size();i++){
		tmp[vec[i]-min].push_back(vec[i]);
	}
	int idx=0;
	for(int i=0;i<numOfBuck;i++){
		for(list<int>::iterator it =tmp[i].begin();it!=tmp[i].end();++it)
			vec[idx++]=*it;
	}
}

int main(){
	int k=10;
	srand((unsigned)(NULL));//放在循环外面
	while(k--){
		int cnt=rand()%10;
		vector<int> t1;
		generate_n(back_inserter(t1),cnt,rand);
		vector<int> t2(t1);
		BuckSort(t1);
		sort(t2.begin(),t2.end());
		if(t1==t2) cout<<cnt<<"ok"<<endl;
		else cout<<"00000000000"<<endl;
	}

	return 0;
}