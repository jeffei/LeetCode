class BitMap
{
public:
	BitMap(int len);
	~BitMap();
	void setVal(int val);
	bool getVal(int val)const;
private:
	int *arr;
	int bitLenOfInt;
};

BitMap::BitMap(int len){
	arr = new int[len];
	memset(arr,0,sizeof(int)*len);
	bitLenOfInt=sizeof(int)*8;
}
BitMap::~BitMap(){
	delete[] arr;
}
void BitMap::setVal(int val){
	arr[val/bitLenOfInt] |= 1 <<(val%bitLenOfInt);
}
bool BitMap::getVal(int val)const{
	return arr[val/bitLenOfInt] & (1<<(val%bitLenOfInt));
}