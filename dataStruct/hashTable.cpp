#include <iostream>
#include <vector>
using namespace std;
struct ListNode{
	int val;
	ListNode* next;
	ListNode(int val):val(val),next(NULL){}
	ListNode(){next=NULL;}
};
class HashTable{
public:
	HashTable(int maxSize):maxSize(maxSize){
		hashVec=vector<ListNode*>(maxSize);
	}
	void insert(int key){
		ListNode *node =new ListNode(key);
		int idx=hash(key);
		if(hashVec[idx]==NULL){hashVec[idx]=node;}
		else{node->next=hashVec[idx];hashVec[idx]=node;}
	}
	bool find(int key){
		int idx=hash(key);
		ListNode *start=hashVec[idx];
		bool flag = false;
		while(start!=NULL){
			if(start->val==key){flag=true;break;}
			start=start->next;
		}
		return flag;
	}

	bool remove(int key){
		int idx=hash(key);
	//	if(!hashVec[idx]) return false;
		ListNode* p=hashVec[idx];
		ListNode* pre=NULL;
		while(p!=NULL && p->val != key) {pre=p;p=p->next;}
		if(p==NULL)return false;
	
		if(pre!=NULL){
			ListNode* tmp=p;
			pre->next=p->next;
			delete tmp;
			tmp=NULL;
		}else{
			delete p;
			hashVec[idx]=NULL;
		}
	}
	~HashTable(){
		for(int i=0;i<maxSize;i++){
			if(hashVec[i]!=NULL){
				clear(hashVec[i]);
			}
		}
	}
private:
	int maxSize;
	int hash(int key){
		return key%maxSize;
	}
	void clear(ListNode* head){
		ListNode* tmp;
		while(head){
			tmp=head;
			head=head->next;
			delete tmp;
			tmp=NULL;
		}
	}
	vector<ListNode*> hashVec;
};
int main(){
	HashTable table(13);
	table.insert(22);
	table.insert(23);
	table.insert(36);
	table.insert(33);
	table.insert(12);
	for(int i=5;i<=95;i+=10) table.insert(i);
	cout<<table.find(24)<<endl;
	table.remove(36);
	table.remove(45);
	cout<<table.remove(86);
	table.remove(23);
	table.remove(75);
	return 0;
}