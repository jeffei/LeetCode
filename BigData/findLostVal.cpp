/*
	42亿数,内存表示42*10^8*4B=16.2G
	位图表示:42*10^8bit/8*10^-9=0.5G=500MB
	该方法保证可用内存至少500MB
	*/
	freopen("in.txt","r",stdin);
	int int_len=sizeof(int)*8;
	int bit_len=0xffffffff/int_len;  
	int* bitMap=new int[bit_len];
	memset(bitMap,0,bit_len); //这一句很关键。。。。。
	int v;
	while(cin>>v) {
		bitMap[v/int_len] |= 1<<(v%int_len);
	}
	fclose(stdin);
	for(int i=0;i<bit_len;i++){
		for(int j=0;j<int_len;j++){
			if((bitMap[i] & 1<<j )==0){
				cout<<( i*int_len+j);
				return -1;
			}
		}
	}