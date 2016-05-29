ListNode* partition(ListNode* head,ListNode* end){
	ListNode* low=head;
	ListNode* i=low;
	int pivot=head->val;
	for(ListNode* p=head->next ; p!=end;p=p->next){
		if(p->val<=pivot){
			i=i->next;
			if(i!=p)swap(i->val,p->val);
		}
	}
	if(i!=low)swap(i->val,low->val);
	return i;
}
void QuickSort(ListNode* head,ListNode* end){
	if(head==end|| head->next==end) return;
	ListNode *pos=partition(head,end);
	QuickSort(head,pos);
	QuickSort(pos->next,end);
}