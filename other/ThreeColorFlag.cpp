vector<int> threeColor(const vector<int>& src){
	vector<int> res(src);
	int blueFlag=0;
	int whiteFlag=0;
	int redFlag=res.size()-1;
	while(whiteFlag<=redFlag){
		if(res[whiteFlag]==2){ //white :2
			whiteFlag++;
		}else if(res[whiteFlag]==1){// blue:1
			swap(res[blueFlag],res[whiteFlag]);
			whiteFlag++;
			blueFlag++;
		}else{ //red:3
			swap(res[redFlag],res[whiteFlag]);
			redFlag--;
		}
	}
	return res;
}