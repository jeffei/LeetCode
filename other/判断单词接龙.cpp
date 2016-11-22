/*
	author:jeffei
	已验证准确性


*/

#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;
void dfs(string start, int cur,vector<bool>& isVisited,const vector<string>& arrs,bool& flag){
	if(cur==arrs.size()-1) flag=true;
	for(int i=0;i<arrs.size();i++){
		if(!flag && !isVisited[i] && arrs[i][0]==start[start.size()-1]){
			isVisited[i]=true;
			dfs(arrs[i],cur+1,isVisited,arrs,flag);
			isVisited[i]=false;
		}
	}
}
bool getResult(const vector<string>& arrs){
	for(int i=0;i<arrs.size();i++){
		vector<bool> isVisited(arrs.size(),false);
		bool flag=false;
		isVisited[i]=true;
		dfs(arrs[i],0,isVisited,arrs,flag);
		if(flag)return true;
	}
	return false;
}


void dfs(char *start, int cur,vector<bool>& isVisited,char** arrs,int num,bool& flag){
	if(cur==num-1) flag=true;
	for(int i=0;i<num;i++){
		if(!flag && !isVisited[i] && arrs[i][0]==start[strlen(start)-1]){
			isVisited[i]=true;
			dfs(arrs[i],cur+1,isVisited,arrs,num,flag);
			isVisited[i]=false;
		}
	}
}
bool getResult(char** arrs,int num){
	for(int i=0;i<num;i++){
		vector<bool> isVisited(num,false);
		bool flag=false;
		isVisited[i]=true;
		dfs(arrs[i],0,isVisited,arrs,num,flag);
		if(flag)return true;
	}
	return false;
}
int main(){
	char* strs[]={"ebd",
					"gde",
					"efg"
	};
	bool flag=getResult(strs,3);
	//vector<string> arrs;
	//arrs.push_back("aba");
	//arrs.push_back("bb");
	////arrs.push_back("efg");
	//bool flag=getResult(arrs);
	return 0;
}