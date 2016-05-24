vector<int> prim(int N){
	map<int,bool> maps;
	for(int i=2;i<=N;i++)
		maps[i]=true;	
	map<int,bool>::iterator it=maps.begin();
	for(;it!=maps.end();it++){
		while(it!=maps.end()&&it->second==false) it++;
		if(it==maps.end()) break;
		map<int,bool>::iterator it1=next(it);
		for(;it1!=maps.end();it1++){
			if(it1->first%it->first==0 &&maps[it1->first]==true){
				maps[it1->first]=false;
			}
		}
	}
	vector<int> res;
	for(map<int,bool>::iterator iter=maps.begin();iter!=maps.end();iter++){
		if(iter->second)
			res.push_back(iter->first);
	}
	return res;
}