/*
	只用10M空间
	42亿数,内存表示42*10^8*4B=16.2G
	位图表示:42*10^8bit/8*10^-9=0.5G=500MB
	必须保证可用内存至少500MB
	
	分块处理
	1.10M空间 可以容纳 10*10^3*8=8*10^4个数，亦即每个分块的最大容量不超过8万个数
	2. 分的块数BlockNum=总数/每块容量(BlockSize)
	

*/

int main(){
	freopen("in.txt","r",stdin);
	int len_int2bit=sizeof(int)*8;
	int totalNum = 20000;//测试数据集
	int blockSize= 2000;
	int blockNum=totalNum/blockSize;
	std::vector<int> block(blockNum,0);
	int bit_len=blockSize/len_int2bit+1;//位图的大小
	std::vector<int> bitMap(bit_len,0);
	int val;
	while(cin>>val) ++block[val/blockSize];
	fclose(stdin);
	int start=-1; //找出那一块少数据：
	for(int i=0;i<blockNum;i++){
		if(block[i]<blockSize){
			start=i*blockSize;
			break;
		}
	}

	freopen("in.txt","r",stdin);
	cin.clear();
	while(cin>>val){
		if(val>=start && val<start+blockSize){
			val-=start;
			bitMap[val/len_int2bit] |= 1<<val%len_int2bit;
		}
	}
	fclose(stdin);

	for(int i=0;i<bit_len;i++){
		for (int j = 0; j < len_int2bit; ++j)
		{
			if((bitMap[i] & (1<<j))==0){
				cout<<i*len_int2bit+j+start;
			}
		}
	}
	return 0;
}
