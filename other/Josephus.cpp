#include<iostream>
#include <list>
#include <vector>
using namespace std;
typedef list<int>::iterator Liter;
vector<int> Josephus(int num,int startPos,int step){
	vector<int> ret;
	list<int> circle;
	for(int i=1;i<=num;++i) circle.insert(circle.end(),i);
	Liter iter=circle.begin();
	while(--startPos>0) iter++;
	while(!circle.empty()){
		for(int i=1;i<step;i++){
			iter++; 
			if(iter==circle.end()){iter=circle.begin();}
		}
		Liter oldIter=iter;
		ret.push_back(*oldIter);
		iter++;if(iter==circle.end()){iter=circle.begin();}
		circle.erase(oldIter);
	}
	return ret;
}

void Joseph(int n,  int s,int step)
{
	int i,j,w;
	int s1 = s;
	int a[100] = {0};
	for(i = 0; i < n; i++) //把n个人的序号放入数组a[]中；
	{
		a[i] = i + 1;
	}
	for(i = n; i>= 2; i--)
	{
		s1 = (s1+step-1)%i; //s1每次出圈人的位置
		if(s1 == 0) //如果s1等于0，则说明要开始报数的人是最后一个人
		{
			s1 = i; //把此时变量i的值赋给s1
		}
		w = a[s1-1]; //把每次出圈人的序号赋给w
		for(j = s1; j < i; j++)
		{
			a[j-1] = a[j];
		}
		a[i-1] = w; //把每次出圈人的序号赋给倒数第i个位置上
	}
	for(int k = n-1; k >= 0; k--)
		cout<<a[k]<<" ";
	cout<<endl;
}

int main(){
	vector<int> test  = Josephus(9,2,3);
	Joseph(9,2,3);
	return 0;
}