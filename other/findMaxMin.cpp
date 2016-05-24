/*
	FindMaxMin with O(1.5n)
	关键将数组长度扩展至偶数
*/
struct Point{
	int x;int y;
	Point(int x,int y):x(x),y(y){}
};
Point findMaxMin(vector<int>& vec){
	for(int i=0;i+1<vec.size();i+=2){
		if(vec[i+1]<vec[i]) swap(vec[i],vec[i+1]);
	}
	if(vec.size()%2) vec.push_back(vec.back());
	Point p(vec[0],vec[1]);
	for(int i=0;i<vec.size();i+=2)
		if(vec[i]<p.x) p.x=vec[i];
	for(int i=1;i<vec.size();i+=2)
		if(vec[i]>p.y) p.y=vec[i];
	return p;
}